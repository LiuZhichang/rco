#pragma once

#include <stdlib.h>

namespace rco {
	namespace core {

		typedef void(*co_fn)(void*);
		struct Context {
			void* rsp;
			void* rbp;
			void* rax;
			void* rbx;
			void* rdi;
			void* r12;
			void* r13;
			void* r14;
			void* r15;

			char* sp;
			size_t ss;
		};

		extern "C" {
			void context_init(Context& ctx);
			void context_make(Context& ctx, co_fn pfn, void* arg);
			void context_jump(Context*, Context*) asm("context_jump");
		}
	}
}

