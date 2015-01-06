#include <cassert>

#define expect(...) assert((__VA_ARGS__))
#define expect_eq(t1, t2) assert((t1 == t2))
#define expect_neq(t1, t2) assert((t1 != t2))

struct test {
    template<class Test>
    test(const Test& test) {
        test();
    }
};

struct test_skip {
    template<class Test>
    test_skip(const Test&) { }
};

template<class T>
struct test_type {
    using type = T;
};

int main() { }

