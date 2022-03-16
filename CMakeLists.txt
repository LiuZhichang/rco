cmake_minimum_required(VERSION 3.12)

project(rco)

set(SRC

	core/asm/context_jump.S
	core/details/context.cpp
	core/rcontext.cpp

	task/task.cpp

	scheduler/processer.cpp
	scheduler/scheduler.cpp

	cpc/channel.cpp

	)

set(CMAKE_CXX_FLAGS "-m32")

enable_language(ASM)

include_directories(./third_party/jemalloc/include)
link_directories(./third_party/jemalloc/lib)

target_link_libraries(${PROJECT_NAME} jemalloc)

add_library(${PROJECT_NAME} ${SRC})
