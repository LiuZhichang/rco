#include <iostream>

#include "../cpc/channel.h"


int main(int argc, char** argv) {

	rco::Channel<int> ch(10);

	for(int i = 0; i < 10; ++i) {
		ch << i;
	}

	for(int i = 0; i < 10; ++i) {
		int num;
		ch >> num;
		std::cout << num << std::endl;
	}

	return 0;
}
