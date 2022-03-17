#include "task.h"

#include <functional>

rco::Task::Task(Execute exec, size_t stack_size)
	: ctx(&Task::DoWork, this, stack_size)
	, execute(std::move(exec))
	, exec_state(State::eRunnable)
	  , processer(nullptr)
	  , unique_id(0){

	  }

rco::Task::~Task() {

}

void rco::Task::yield() {
	ctx.swap_out();
}

void rco::Task::resume() {
	ctx.swap_in();
}

void rco::Task::run() {
	try {
		execute();
	} catch(...) {
		execute = Execute();
	}

	exec_state = State::eFinish;
}

void rco::Task::DoWork(void* arg) {
	Task* task = (Task*)arg;
	task->run();
}
