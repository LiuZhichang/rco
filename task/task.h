#pragma once

#include <functional>

#include "../common/internal.h"
#include "../common/noncopyable.h"
#include "../common/rcomem.h"

#include "../core/rcontext.h"
#include "../rcds/tsqueue.h"

namespace rco {

	class Processer;
	class Switcher;

	class Task : public Noncopyable, public Intrusive_queue, public Shared_ref {
		public:
			typedef std::function<void()> Execute;

			/**
			 * @brief 协程状态，协程同一时刻只会有一种状态，因此未使用Flags类
			 */
			enum class State {
				eRunnable,		// 运行
				eWait,			// 阻塞
				eFinish			// 结束
			};

			struct Attribute {
				size_t stack_size;

				Attribute()
					: stack_size(0) {

					}
			};

			/**
			 * @brief Task构造函数
			 *
			 * @param[in] exec			任务执行实体
			 * @param[in] stack_size	协程栈大小，默认2K
			 */
			Task(Execute exec, size_t stack_size = (1024 << 1));
			~Task();

			/**
			 * @brief 协程挂起
			 */
			void yield();

			/**
			 * @brief 协程恢复
			 */
			void resume();

			RCO_INLINE void set_id(uint64_t id) {
				unique_id = id;
			}

			RCO_INLINE uint64_t id() const {
				return unique_id;
			}

			RCO_INLINE void set_state(State state) {
				exec_state = state;
			}

			RCO_INLINE State state() const {
				return exec_state;
			}

			RCO_INLINE void set_own_proc(Processer* proc) {
				processer = proc;
			}

			RCO_INLINE Processer* own_proc() const {
				return processer;
			}
		private:
			void run();
			RCO_STATIC void DoWork(void *arg);

			RContext   ctx;
			Execute	   execute;
			State	   exec_state;
			Processer *processer;
			Switcher  *switcher;
			uint64_t   unique_id;
	};
}
