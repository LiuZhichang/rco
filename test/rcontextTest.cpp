#include <core/rcontext.h>

#include <iostream>

#include <assert.h>

struct log {
	log(const char* startMsg, const char* finishMsg,  const char* func)
		: at_finsih_msg(finishMsg)
		  , func(func){

			  assert(startMsg);
			  assert(finishMsg);

			  std::cout << "[FUNCTION:" << func << "] :" << "\t" << startMsg << std::endl;
		  }

	~log() {
		if(at_finsih_msg) {
			std::cout << "[FUNCTION:" << func << "] :" << "\t" << at_finsih_msg << std::endl;
		}
	}

	private:
	const char* at_finsih_msg;
	const char* func;
};

#define LOG_NAME_CAT(s1, s2) s1##s2
#define LOG(at_start, at_finish) \
	log LOG_NAME_CAT(s1,s2)(at_start, at_finish, __func__)

#define SIZE_1K 1024

void task(void* arg) {
	rco::RContext* ctx = (rco::RContext*)arg;

	LOG("task start", "task finish");

	{
		LOG("task suspend", "task resume");
		ctx->suspend();
	}

	{
		LOG("task suspend", "task resume");
		ctx->suspend();
	}
}

int main(int argc, char** argv) {

	LOG("main start", "main finish");

	rco::RContext::GetCtx();
	rco::RContext ctx(task, (void*)&ctx, SIZE_1K << 1);

	{
		LOG("main suspend", "main resume");
		ctx.resume();
	}

	{
		LOG("main suspend", "main resume");
		ctx.resume();
	}
}
