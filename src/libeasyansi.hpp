#pragma once
#include <iostream>
#include <string>

namespace libeasyansi {
    inline std::ostream &ansi(std::ostream &os, const std::string code){
        #ifdef _WIN32
        return os << "`e[" << code << "m";
        #else
        return os << "\033[" << code << "m";
        #endif
 }
}