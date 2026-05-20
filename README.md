# libeasyansi
![GitHub License](https://img.shields.io/github/license/duderain/libeasyansi)

A simple header-only wrapper for ANSI escape codes so you don't have to account for it in another operating system.

# How to use
Very easy to use, and will automatically set the terminal to ANSI code accepting if you compile for windows.
```cpp
int main(){
    std::cout << easyansi::invert << easyansi::ansi("32") << "this is the power of libeasyansi!" << easyansi::reset << std::endl;
}
```