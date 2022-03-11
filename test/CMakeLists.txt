cmake_minimum_required(VERSION 3.12)

project(Test)

include_directories(../../Rco)

enable_language(C ASM)

set(SRC

	../core/asm/context_jump.S
	../core/details/context.cpp
	../core/rcontext.cpp
	)

add_executable(coTest cotest.cpp ${SRC})
add_executable(coTest1 cotest1.cpp ${SRC})
add_executable(rcontextTest rcontextTest.cpp ${SRC})
