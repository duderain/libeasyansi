# libeasyansi
![GitHub License](https://img.shields.io/github/license/duderain/libeasyansi)

A simple header-only wrapper for ANSI escape codes so you don't have to account for it in another operating system.

# How to use
Include libeasyansi.hpp 

**Basic Usage**:
```cpp
int main(){
    std::cout << easyansi::invert << easyansi::setColour(easyansi::colour::green) << "this is the power of libeasyansi!" << easyansi::resetGraphics("7") << easyansi::italics <<" + with ease of access" << easyansi::reset << std::endl;
    return 0;
}
```
If you are compiling for Windows, the library will automatically set ansi up.