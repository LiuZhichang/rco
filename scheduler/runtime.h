#pragma once

#include <cstdint>
#include <atomic>

namespace rco {
	class Runtime {
		struct Env {
			std::atomic<uint16_t> proc_count;
			std::atomic<uint16_t> gc_threshold;
			Env();
		};
		public:
		static void Sched();
		static void Rco_Exit();
		static void Set_max_procs(uint16_t n);
		static uint16_t CPU_count();
		static void GC();
		static void Set_GC_threshold(std::size_t val);
		static uint16_t GC_threshold();
		private:
		static Env env;
	};
}
