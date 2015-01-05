#include <cxxabi.h>
#include <string>
#include <boost/shared_ptr.hpp>

std::string demangle(const std::string& mangled) {
    char* demangled = abi::__cxa_demangle(mangled.c_str(), 0, 0, 0);
    if (demangled) {
        boost::shared_ptr<char> free(demangled, ::free);
        return demangled;
    }

    return "";
}

int main() {
    assert("int" == demangle(typeid(int).name()));
    assert("std::string" == demangle(typeid(const std::string&).name()));
    return 0;
}

