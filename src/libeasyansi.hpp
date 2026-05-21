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

    //Basic class to wrap a string as a ansi code.
    class ansi{
        public:
            explicit ansi(std::string c) : code(std::move(c)) {}

            friend std::ostream& operator<<(std::ostream& os, const ansi& a){
                return os << "\033[" << a.code << "m";
            };
        private:
            std::string code;
    };
    //Resets graphics.
    TEMPLATE
    OUT &reset(OUT &os){
        return os << "\033[0m";
    }
    //Inverts the colours so fg is bg and bg is fg.
    TEMPLATE
    OUT &invert(OUT &os){
        return os << "\033[7m";
    }
    //Makes the text italic.
    TEMPLATE
    OUT &italics(OUT &os){
        return os << "\033[3m";
    }

    //Makes the text bold.
    TEMPLATE
    OUT &bold(OUT &os){
        return os << "\033[1m";
    }
    
    //Underlines the text.
    TEMPLATE
    OUT &underline(OUT &os){
        return os << "\033[4m";
    }

    //Resets a specific attribute.
    class resetGraphics{
        public:
            explicit resetGraphics(std::string c) : code(std::move(c)) {}

            friend std::ostream& operator<<(std::ostream& os, const resetGraphics& a){
                return os << "\033[2" << a.code << "m";
            };
        private:
            std::string code;
    };
    //Sets Colour.
    class setColour{
        public:
            explicit setColour(easyansi::colour c, bool bg = false) : colour(std::move(c)), background(bg) {}

            friend std::ostream& operator<<(std::ostream& os, const setColour& a){
                std::string number;
                if(a.background){
                    number = "4";
                }
                else{
                    number = "3";
                }
                return os << "\033[" << number << std::to_string(static_cast<int>(a.colour)) << "m";
            };
        private:
            easyansi::colour colour;
            bool background;
    };

}