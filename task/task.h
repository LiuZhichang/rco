#pragma once

#include <functional>

#include "../common/internal.h"
#include "../core/context.h"

namespace rco {
	class Task {
		public:
			typedef std::function<void(void*)> Execute;

			enum class State {
				eRunning,
				eWait,
				eFinish
			};

			RCO_INLINE void suspend();
			RCO_INLINE void resume();

		private:
	};
}
