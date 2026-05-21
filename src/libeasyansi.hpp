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

    class windowsInitalizer { 
    private:
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


    enum class colour : u_int{
        black,
        red,
        green,
        yellow,
        blue,
        magenta,
        cyan,
        white,
        defaultColour = 9
    };


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

    class resetGraphics{
        public:
            explicit resetGraphics(std::string c) : code(std::move(c)) {}

            friend std::ostream& operator<<(std::ostream& os, const resetGraphics& a){
                return os << "\033[2" << a.code << "m";
            };
        private:
            std::string code;
    };

    class setColour{
        public:
            explicit setColour(easyansi::colour c) : colour(std::move(c)) {}

            friend std::ostream& operator<<(std::ostream& os, const setColour& a){
                if(a.background){
                    std::string number = "4";
                }
                else{
                    std::string number = "3";
                }
                return os << "\033[2" << std::to_string(static_cast<int>(a.colour)) << "m";
            };
        private:
            easyansi::colour colour;
            bool background;
    };

}