#include <iostream>

#include <core/details/context.h>

#include <cstring>

rco::core::Context mainCtx;
rco::core::Context ctx;

void alloc(rco::core::Context& co) {
    memset(&co, 0, sizeof(co));
    co.sp = (char*) malloc(1024 << 2);
    co.ss = 1024 << 2;
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
    rco::core::context_jump(&ctx, &mainCtx);
    std::cout << "func1 resume" << std::endl;
    t.show();
    rco::core::context_jump(&ctx, &mainCtx);
}

int main() {
    alloc(mainCtx);
    rco::core::context_make( mainCtx, nullptr, nullptr);

    alloc(ctx);
    T t;
    rco::core::context_make( ctx, func1, &t);

    rco::core::context_jump(&mainCtx, &ctx);

    std::cout << "function main resume" << std::endl;

    rco::core::context_jump(&mainCtx, &ctx);

    std::cout << "function main finish" << std::endl;
    return 0;
}
