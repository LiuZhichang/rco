#include <rcds/cas_rbuf.h>
#include <functional>
#include <iostream>

using namespace rco;

class A {
	public:
		A(int val)
			:value(val){
			}

		A() 
			: value(0) {}

		~A() {
		}

		void show() {
			std::cout << "Value:" << value << std::endl;
		}

	private:
		int value;
};

int main(int arg, char** argv) {

	typedef cas::LockFreeRingBuf<A>::State State;
	typedef cas::LockFreeRingBuf<A>::FlagBits FlagBits;

	std::function<void(FlagBits, const char*)> task = [](FlagBits flag, const char* type) {

		std::cout << flag.to_bitset() << std::endl;
		if(flag & State::eSuccess) {
			std::cout << type << " Success";
		} else {
			std::cout << type << " Failed";
		}

		if(flag & State::eEmpty) {
			std::cout << "\t" << "State Empty";
		}

		if(flag & State::eFull) {
			std::cout << "\t" << "State Full";
		}
		std::cout << "\n" << std::endl;
	};

	cas::LockFreeRingBuf<A> buf(5);
	for(int i = 0; i < 6; ++i) {
		A a(i);
		FlagBits flags = buf.push(std::move(a));

		task(flags, "Push");
	}

	std::cout << "\npop-------------------------------" << std::endl;

	for(int i = 5; i > 0; --i) {
		A a;
		FlagBits flags = buf.pop(a);

		task(flags, "Pop");
	} 

	//cas::LockFreeRingBuf<A>::FlagBits flags = buf.push(std::move(A(5)));

	//std::cout << "Result State:" << flags.to_bitset() << std::endl;


	return 0;
}
