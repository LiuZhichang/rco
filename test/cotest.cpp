#include <core/details/context.h>

#include <iostream>

rco::core::Context mainCtx;
rco::core::Context ctx;

#define log(msg) \
	std::cout << __func__ << ":" << __LINE__ << "\t" << msg << std::endl;

void alloc(rco::core::Context& ctx) {
	rco::core::context_init(ctx);
	size_t size = 1024;
	ctx.ss = size;
	ctx.sp = (char*)malloc(size);
}

void func(void* arg) {

	log("func start");

	log("func resume");
	rco::core::context_jump(&ctx, &mainCtx);
	log((char*)arg);
	log("func resume");
	rco::core::context_jump(&ctx, &mainCtx);

	log("func finish");
}

int main(int argc, char** argv) {
	
	log("main start");

//	alloc(mainCtx);
	rco::core::context_init(mainCtx);
	rco::core::context_make(mainCtx, nullptr, nullptr);

	alloc(ctx);
	char* message = "some message";
	rco::core::context_make(ctx, func, (void*)message);

	log("main resume");
	rco::core::context_jump(&mainCtx, &ctx);
	log("main resume");
	rco::core::context_jump(&mainCtx, &ctx);
	
	log("main finish");

	return 0;
}
