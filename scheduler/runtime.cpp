#include "runtime.h"

#include <thread>

#include "processer.h"
#include "scheduler.h"

rco::Runtime::Env rco::Runtime::env;

rco::Runtime::Env::Env()
	: proc_count(std::thread::hardware_concurrency())
	  ,gc_threshold(16){

	  }

void rco::Runtime::Sched() {
	Processer::CoYield();
}

void rco::Runtime::Rco_Exit() {

}

void rco::Runtime::Set_max_procs(uint16_t n) {
	unsigned int max = std::thread::hardware_concurrency();
	env.proc_count = (n > max) ? max : n;
}

uint16_t rco::Runtime::CPU_count() {
	return env.proc_count;
}

void rco::Runtime::GC() {
	Processer::CurrentScheduler()->GC();
}

void rco::Runtime::Set_GC_threshold(std::size_t val) {
	env.gc_threshold = val;
	Processer::CurrentScheduler()->update_threshold(env.gc_threshold);
}

uint16_t rco::Runtime::GC_threshold() {
	return env.gc_threshold;
}

