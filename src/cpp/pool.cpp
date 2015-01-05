#include <cassert>

template<typename... TArgs>
class pool : TArgs...
{
public:
    template<typename... Args>
    explicit pool(Args&... args)
        : Args(args)...
    { }

    template<typename T>
    T& get() {
        return static_cast<T&>(*this);
    }
};

class a {};
class b {};

int main() {
    a a_;
    b b_;

    {
    pool<a, b> p(a_, b_);
    assert(&a_ == &p.get<a>());
    assert(&b_ == &p.get<b>());
    }

    {
    pool<a, b> p(b_, a_);
    assert(&a_ == &p.get<a>());
    assert(&b_ == &p.get<b>());
    }

    return 0;
}

