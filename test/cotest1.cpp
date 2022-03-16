#include <iostream>

#include <core/details/context.h>

#include <cstring>

rco::core::Context mainCtx;
rco::core::Context ctx;

void alloc(rco::core::Context& co) {
    memset(&co, 0, sizeof(co));
    co.stack_ptr = (char*) malloc(1024 << 2);
    co.stack_size = 1024 << 2;
}

class T {
public:
    void show() {
        std::cout << "show" << std::endl;
    }
};

void func1(void* arg) {
    T t = *(T*)arg;
    std::cout << "func1" << std::endl;
    rco::core::rco_jump_context(&ctx, &mainCtx);
    std::cout << "func1 resume" << std::endl;
    t.show();
    rco::core::rco_jump_context(&ctx, &mainCtx);
}

int main() {
    alloc(mainCtx);
    rco::core::rco_make_context(&mainCtx, nullptr, nullptr);

    alloc(ctx);
    T t;
    rco::core::rco_make_context(&ctx, func1, &t);

    rco::core::rco_jump_context(&mainCtx, &ctx);

    std::cout << "function main resume" << std::endl;

    rco::core::rco_jump_context(&mainCtx, &ctx);

    std::cout << "function main finish" << std::endl;
    return 0;
}
