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

enable_language(ASM)

add_library(${PROJECT_NAME} ${SRC})
