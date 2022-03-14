#include <task/task.h>
#include <defer/defer.h>

#include <iostream>

int main(int argc, char** argv) {

	rco::RContext::GetCtx();

	rco::Task task([&](){
			std::cout << "execute task" << std::endl;
			task.suspend();
			}, 1024);

	task.resume();
	
	defer {
		std::cout << "main finish" << std::endl;
	};

	std::cout << "main resume" << std::endl;


	return 0;
}
