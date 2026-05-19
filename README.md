# libeasyansi
![GitHub License](https://img.shields.io/github/license/duderain/libeasyansi)

A simple header-only wrapper for ANSI escape codes so you don't have to account for it in another operating system.

# How to use
Very easy to use, and will automatically set the terminal to ANSI code accepting if you compile for windows.
```C++
#include <iostream>
#include "libeasyansi.hpp"

int main(){
    std::cout << easyansi::ansi("31") << "libeasyansi" << easyansi::ansi("0") << std::endl;
    return 0;
}
```