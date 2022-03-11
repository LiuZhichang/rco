cmake_minimum_required(VERSION 3.12)

project(rco)

set(SRC

	core/asm/context_jump.S
	core/context.cpp
	)

enable_language(ASM)

add_library(${PROJECT_NAME} ${SRC})
