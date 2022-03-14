#include <thread>
#include <mutex>
#include <condition_variable>

#include <rcds/cas_rbuf.h>

using namespace rco;

const uint64_t MAX_SIZE = 100000;

cas::LockFreeRingBuf<int> buf(MAX_SIZE);

using State = cas::LockFreeRingBuf<int>::State;
using FlagBits = cas::LockFreeRingBuf<int>::FlagBits;

std::condition_variable cv;
std::mutex mtx;

FlagBits isFull(FlagBits flag) {
	return (flag & State::eFull);
}

FlagBits isEmpty(FlagBits flag) {
	return (flag & State::eEmpty);
}

void producer() {
	int i = 0;
	std::unique_lock<std::mutex> uni_lck(mtx);
	while(true) {
		FlagBits flags = buf.push(std::move(i));

		if(!(flags & State::eSuccess)) {
			if(isFull(flags)) {
				cv.notify_one();
			}
		} else {
			std::cout << "Producer:" << i << std::endl;
		}

		++i;
	}
}

void consumer() {
	std::unique_lock<std::mutex> uni_lck(mtx);

	while(true) {
		int val;
		FlagBits flags = buf.pop(val);
		if(!(flags & State::eSuccess)) {
			if(isEmpty(flags)) {
				cv.wait(uni_lck);
			}
		} else {
			std::cout << "Consumer " << std::this_thread::get_id() << ":" << val << std::endl;
		}

	}
}

int main(int argc, char** argv) {

	std::thread t1(producer);
	std::thread t2(consumer);
	std::thread t3(consumer);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
