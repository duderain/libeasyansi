#pragma once
#include <iostream>
#include <string>

namespace libeasyansi {
    inline std::ostream &ansi(std::ostream &os, const std::string code){
        #ifdef _WIN32
        return os << "`e[" << code;
        #else
        return os << "\033[" << code;
        #endif
 }
}