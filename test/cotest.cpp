#include <core/details/context.h>

#include <iostream>

rco::core::Context mainCtx;
rco::core::Context ctx;

#define log(msg) \
	std::cout << __func__ << ":" << __LINE__ << "\t" << msg << std::endl;

void alloc(rco::core::Context& ctx) {
	size_t size = 1024;
	ctx.stack_size= size;
	ctx.stack_ptr = (void*)malloc(size);
}

void func(void* arg) {

	log("func start");

	log("func resume");
	rco::core::rco_jump_context(&ctx, &mainCtx);
	log((char*)arg);
	log("func resume");
	rco::core::rco_jump_context(&ctx, &mainCtx);

	log("func finish");
}

int main(int argc, char** argv) {
	
	log("main start");

//	alloc(mainCtx);
	rco::core::rco_make_context(&mainCtx, nullptr, nullptr);

	alloc(ctx);
	char* message = "some message";
	rco::core::rco_make_context(&ctx, func, (void*)message);

	log("main resume");
	rco::core::rco_jump_context(&mainCtx, &ctx);
	log("main resume");
	rco::core::rco_jump_context(&mainCtx, &ctx);
	
	log("main finish");

	return 0;
}
