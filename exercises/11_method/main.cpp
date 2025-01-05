#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached = 0;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        for (; this->cached < i; ++this->cached) {
            if (this->cached == 0) {
                this->cache[this->cached] = 1;
            } else if (this->cached == 1) {
                this->cache[this->cached] = 1;
            } else {
                this->cache[this->cached] = this->cache[this->cached - 1] + this->cache[this->cached - 2];
            }
        }
        return this->cache[i-1];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
