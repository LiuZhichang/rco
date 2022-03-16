#include "runtime.h"

#include <thread>

void rco::Runtime::rco_sched() {

}

void rco::Runtime::rco_exit() {

}

void rco::Runtime::rco_max_procs(uint8_t n) {

}

uint8_t rco::Runtime::cpu_count() {
	return std::thread::hardware_concurrency();
}
