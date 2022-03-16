#pragma once

#include "../task/task.h"

#include <thread>

class Scheduler;

namespace rco {
	class Processer {
		friend class Scheduler;
		public:

		private:
		Scheduler*		own_scheduler; // 所属的调度器
		std::thread::id id;

		Task*			running_task;
		Task*			next_task;


	};
}
