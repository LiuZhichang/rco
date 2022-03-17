#pragma once

#include <atomic>

#include "internal.h"

namespace rco {

	class Spink_lock {
		public:
			Spink_lock()
				: flag{false} {

				}

			RCO_INLINE void lock() {
				while(flag.test_and_set(std::memory_order_acquire));
			}

			RCO_INLINE void unlock() {
				flag.clear(std::memory_order_release);
			}

			RCO_INLINE bool try_lock() {
				return !flag.test_and_set(std::memory_order_acquire);
			}

		private:
			std::atomic_flag flag;
	};

	class Virtual_lock {
		public:
			Virtual_lock() {

			}

			RCO_INLINE void lock() {

			}

			RCO_INLINE void unlock() {

			}

			RCO_INLINE bool try_lock() {
				return false;
			}
	};

	class Virtual_lock_guard {
		public:
		template<typename Mutex_t>
			explicit Virtual_lock_guard(Mutex_t&) {}
	};

}
