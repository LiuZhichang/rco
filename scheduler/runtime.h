#pragma once

#include <cstdint>

namespace rco {
	class Runtime {
		public:
			static void rco_sched();
			static void rco_exit();
			static void rco_max_procs(uint8_t n);
			static uint8_t cpu_count();
	};
}
