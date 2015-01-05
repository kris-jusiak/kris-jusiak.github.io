#include <iostream>
#include <boost/units/detail/utility.hpp>

namespace {

template<int Value = 0, typename T = void>
struct Print
{
    unsigned : 80;
    typedef T type;
};

#define PRINT(T) Print<__LINE__, T>

template<typename T>
std::string print() {
    return boost::units::detail::demangle(typeid(T).name());
}

template<typename T>
std::string print(const T& p_t) {
    return boost::units::detail::demangle(typeid(p_t).name());
}

} // namespace

class hello_world { };

class warn : PRINT(hello_world) // print.cpp:29:14: warning: ...Print<29, hello_world>...
{ };

int main() {
    std::cout << print<int>() << std::endl; //int

    int i = 0;
    std::cout << print(i) << std::endl; // int

}

