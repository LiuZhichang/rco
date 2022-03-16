#include <task/task.h>
#include <defer/defer.h>

#include <iostream>


int main(int argc, char** argv) {

	auto mainCtx = rco::RContext::GetCtx();

	rco::Task task_func([&](){

			std::cout << "execute func" << std::endl;

			rco::Task task([&](){
					std::cout << "execute task" << std::endl;
					task.suspend();
					}, 1024);
			task.resume();

			task_func.suspend();
			});
	task_func.resume();

	defer {
		std::cout << "main finish" << std::endl;
	};

	std::cout << "main resume" << std::endl;


	return 0;
}
