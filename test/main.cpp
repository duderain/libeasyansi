#include <iostream>
#include "../src/libeasyansi.hpp"


int main(){
    std::cout << easyansi::invert << easyansi::ansi("32") << "this is the power of libeasyansi!" << easyansi::reset << std::endl;
}