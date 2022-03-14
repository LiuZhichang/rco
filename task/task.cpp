#include "task.h"

#include <functional>

rco::Task::Task(Execute exec, size_t stack_size)
	: ctx(&Task::DoWork, this, stack_size)
	  , execute(std::move(exec)) {

	  }

rco::Task::~Task() {
	
}

void rco::Task::suspend() {
	ctx.suspend();
}

void rco::Task::resume() {
	ctx.resume();
}

void rco::Task::run() {
	try {
		execute();
	} catch(...) {
		execute = Execute();
	}

	state = State::eFinish;
}

void rco::Task::DoWork(void* arg) {
	Task* task = (Task*)arg;
	task->run();
}
