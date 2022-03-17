#include "scheduler.h"

#include <atomic>
#include <cstdlib>
#include <functional>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>

#include "processer.h"
#include "runtime.h"

struct Exit_Op {
	std::mutex ex_mtx;
	std::vector<std::function<void()> >* ex_cbs;

	Exit_Op() {
		ex_cbs = new std::vector<std::function<void()> >;
	}

	~Exit_Op() {
		delete ex_cbs;
	}

	RCO_STATIC Exit_Op& Instance() {
		RCO_STATIC Exit_Op ex_op;
		return ex_op;
	}

	RCO_INLINE void exec_cb() {
		for(auto cb : *ex_cbs) {
			cb();
		}
		ex_cbs->clear();
	}

	RCO_INLINE void register_cb(std::function<void()>&& cb) {
		ex_cbs->push_back(std::move(cb));
	}
};

struct ID_Generator {

	RCO_STATIC ID_Generator& Instance() {
		RCO_STATIC ID_Generator generator;
		return generator;
	}

	RCO_INLINE uint64_t make() {
		return ++id;
	}

	ID_Generator()
		: id(0) {

		}

	private:
	std::atomic<uint64_t> id;
};

void rco::Scheduler::OnExit() {
	atexit(&OnExitDoWork);
}

void rco::Scheduler::OnExitDoWork() {
	Exit_Op::Instance().exec_cb();
}

rco::Scheduler::Scheduler()
	: running(true)
	  , min_thread_count(1)
	  , max_thread_count(1){
		  // 初始执行器
		  processers.push_back(new Processer(this, 0));
	  }

rco::Scheduler::~Scheduler() {
	stop();
}

rco::Scheduler& rco::Scheduler::Instance() {
	RCO_STATIC Scheduler s_sched;
	return s_sched;
}

rco::Scheduler* rco::Scheduler::Make() {
	Scheduler* sched = new Scheduler;
	std::unique_lock<std::mutex> scope_lock(Exit_Op::Instance().ex_mtx);
	// 注册资源回收回调
	Exit_Op::Instance().register_cb(
			std::move([=]{
				delete sched;
				})
			);

	return sched;
}

void rco::Scheduler::make_task(const Task::Execute& execute, const Task::Attribute& attr) {
	Task* task = new Task(execute, attr.stack_size);
	// 注册资源回收回调
	task->set_destructor(Destructor(&Scheduler::DelTask, this));
	// 生成协程id
	uint64_t id = ID_Generator::Instance().make();
	task->set_id(id);

	++task_count;

	add_task(task);
}

bool rco::Scheduler::working() {
	return !!Processer::CurrentTask();
}

bool rco::Scheduler::empty() {
	return (task_count == 0);
}

void rco::Scheduler::start(uint16_t min_thread_cnt, uint16_t max_thread_cnt) {
	if(!started.try_lock())	{
		throw std::logic_error("repeated call start func.");
	}

	if(min_thread_cnt == 0) {
		min_thread_cnt = Runtime::CPU_count();
	}

	if(max_thread_cnt == 0 || max_thread_cnt < min_thread_cnt) {
		max_thread_cnt = min_thread_cnt;
	}

	min_thread_count = min_thread_cnt;
	max_thread_count = max_thread_cnt;

	Processer* main_proc = processers[0];

	// 创建执行器
	for(int i = 0; i < min_thread_count - 1; ++i) {
		make_process_thread();
	}

	// 如果最大线程数大于1
	if(max_thread_count > 1) {
		// 开启调度线程(也可叫分发线程，用来委派任务)
		std::thread th([this]{
				this->do_dispatch();
				});
		dispatch_thread.swap(th);
	} else {
		throw std::runtime_error("no dispatch thread");
	}
	// 主执行器开始调度
	main_proc->scheduling();
}

void rco::Scheduler::stop() {
	std::unique_lock<std::mutex> scope_lock(mutex);
	
	// 如果已经停止 直接返回
	if(!running) return;

	// 更新运行状态
	running = false;
	
	// 唤醒所有执行器，执行任务
	for(Processer* p : processers) {
		if(p) {
			p->wait_notify();
		}
	}
	
	// 回收线程资源
	if(dispatch_thread.joinable()) {
		dispatch_thread.join();
	}

	if(timer_thread.joinable()) {
		timer_thread.join();
	}
}

void rco::Scheduler::DelTask(rco::Ref_obj* task, void* arg) {
	Scheduler* self = static_cast<Scheduler*>(arg);
	delete task;
	--self->task_count;
}


void rco::Scheduler::make_process_thread() {
	Processer* p = new Processer(this, processers.size());
		
	// 开启调度线程
	std::thread([this,p]{
			p->scheduling();
			}).detach();

	// 记录该执行器
	processers.push_back(p);
}

void rco::Scheduler::add_task(Task* task) {
	Processer* proc = task->own_proc();
	if(proc && proc->active) {
		proc->add_task(task);
		return;
	}

	proc = Processer::CurrentProcesser();
	if(proc && proc->active && proc->own_scheduler() == this) {
		proc->add_task(task);
		return;
	}
}

void rco::Scheduler::GC() {
	for(Processer* p : processers) {
		p->gc();
	}
}

void rco::Scheduler::update_threshold(size_t n) {
	for(Processer* p : processers) {
		p->set_threshold(n);
	}
}
