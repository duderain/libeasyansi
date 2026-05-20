#pragma once
#include <iostream>
#include <string>

#define TEMPLATE template <class CharT, class TraitsT>
#define OUT std::basic_ostream<CharT, TraitsT>

#ifdef _WIN32
#include <windows.h>
#endif

namespace easyansi {

    #ifdef _WIN32

    struct windowsInitalizer { 
        windowsInitalizer() {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            if (hOut != INVALID_HANDLE_VALUE && GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
            }
        }
    };
     easyansi::windowsInitalizer dummy;
    #endif


    struct ansi {
        std::string code;
        explicit ansi(std::string c) : code(std::move(c)) {}
    };

    inline std::ostream& operator<<(std::ostream& os, const ansi& a){
        return os << "\033[" << a.code << "m";
    }

    TEMPLATE
    OUT &reset(OUT &os){
        return os << "\033[0m";
    }

    TEMPLATE
    OUT &invert(OUT &os){
        return os << "\033[7m";
    }
    
}