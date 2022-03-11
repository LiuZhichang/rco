
#include "context.h"

#include <cstring>

void rco::core::context_init(Context& ctx) {
	std::memset(&ctx, 0, sizeof(ctx));
}

void rco::core::context_make(Context& ctx, co_fn pfn, void* arg) {
	if(!ctx.sp) {
		return;
	}
	char* sp = ctx.sp + ctx.ss - sizeof(void*);
	sp = (char*)((unsigned long)sp & -16LL);

	void** ret = (void**)sp;

	*ret = (void*)pfn;

	ctx.rsp = sp;
	ctx.rax = ret;
	ctx.rdi = arg;
}
