cmake_minimum_required(VERSION 3.12)

project(Test)

include_directories(../../Rco)

enable_language(C ASM)

set(CMAKE_CXX_STANDARD 14)

set(SRC

	../core/asm/context_jump.S
	../core/details/context.cpp
	../core/rcontext.cpp
	../task/task.cpp
	../rcds/cas_rbuf.h

	../common/flags.h
	)

add_executable(coTest cotest.cpp ${SRC})
add_executable(coTest1 cotest1.cpp ${SRC})
add_executable(rcontextTest rcontextTest.cpp ${SRC})
add_executable(taskTest taskTest.cpp ${SRC})

add_executable(rbufTest rbufTest.cpp ${SRC})
add_executable(rbufTestForThread rbufTestForThread.cpp ${SRC})

target_link_libraries(rbufTestForThread pthread)
