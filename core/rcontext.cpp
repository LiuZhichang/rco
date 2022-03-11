#include "rcontext.h"
#include "details/context.h"

#include <assert.h>

struct ContextIniter {
	rco::RContext ctx;
	ContextIniter()
		: ctx(nullptr, nullptr,0) {

		}
};

rco::RContext::RContext(rctx_fn pfn, void* arg, size_t stack_size) {

	core::context_init(ctx);

	ctx.ss = stack_size;
	ctx.sp = (char*)malloc(stack_size);

	core::context_make(ctx, pfn, arg);
}

rco::RContext::~RContext() {

}

void rco::RContext::suspend() {
//	assert(&GetCtx().ctx == &ctx);
	core::context_jump(&ctx, &GetCtx().ctx);
}

void rco::RContext::resume() {
//	assert(&GetCtx().ctx == &ctx);
	core::context_jump(&GetCtx().ctx, &ctx);
}

rco::RContext& rco::RContext::GetCtx() {
	RCO_STATIC thread_local ContextIniter s_ctx_initer;

	return s_ctx_initer.ctx;
}

