#include <cassert>
#include <memory>
#include "di.hpp"

struct A { };

struct B
{
public:
    CTOR(B, int, std::shared_ptr<A> a)
        : a(a)
    { }

    std::shared_ptr<A> a;
};

struct C
{
    CTOR(C, int, double, int, std::shared_ptr<A> a, std::shared_ptr<B> b) {
        assert(b->a == a);
    }
};

int main() {
    C c = di<>().create<C>();
    return 0;
}

