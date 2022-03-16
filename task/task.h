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
				eRunning,		// 运行
				eWait,			// 阻塞
				eFinish			// 结束
			};

			/**
			 * @brief Task构造函数
			 *
			 * @param[in] exec			任务执行实体
			 * @param[in] stack_size	协程栈大小，默认2K
			 */
			Task(Execute exec, size_t stack_size = (1024 << 1) );
			~Task();

			/**
			 * @brief 协程挂起
			 */
			void suspend();

			/**
			 * @brief 协程恢复
			 */
			void resume();

		private:
			void run();
			RCO_STATIC void DoWork(void *arg);

			RContext   ctx;
			Execute	   execute;
			State	   state;
			Processer *processer;
			Switcher  *switcher;
	};
}
