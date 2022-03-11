#pragma once

#include "../common/internal.h"

#include "details/context.h"

#include <cstdlib>
#include <memory>

namespace rco {

	class RContext {
		public:
			typedef core::co_fn rctx_fn;

			explicit RContext(rctx_fn pfn, void* arg, size_t stack_size);
			~RContext();

			void suspend();
			void resume();


			RCO_STATIC RContext& GetCtx();
		private:
			core::Context ctx;
			core::co_fn   pfn;
			void*		  pAllocator;
	};
}
