#pragma once
#include <iostream>
#include <string>
#include <utility>

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

    class ansi{
        public:
            explicit ansi(std::string c) : code(std::move(c)) {}

            friend std::ostream& operator<<(std::ostream& os, const ansi& a){
                return os << "\033[" << a.code << "m";
            };
        private:
            std::string code;
    };

    TEMPLATE
    OUT &reset(OUT &os){
        return os << "\033[0m";
    }

    TEMPLATE
    OUT &invert(OUT &os){
        return os << "\033[7m";
    }

    TEMPLATE
    OUT &italics(OUT &os){
        return os << "\033[3m";
    }

    struct resetGraphics {
        std::string code;
        explicit resetGraphics(std::string c) : code(std::move(c)) {}
    };
    
    inline std::ostream& operator<<(std::ostream &os, const resetGraphics& a){
        return os << "\033[2" << a.code << "m";
    }
}