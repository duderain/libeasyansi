#include <iostream>
#include "../src/libeasyansi.hpp"


int main(){
    std::cout << easyansi::invert << easyansi::setColour(easyansi::colour::green) << "this is the power of libeasyansi!" << easyansi::resetGraphics("7") << easyansi::italics <<" + with ease of access" << easyansi::reset << std::endl;
    return 0;
}