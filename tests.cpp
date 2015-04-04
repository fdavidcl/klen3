#include <iostream>
#include "kleene.cpp"

int main() {
    /**
        Tests for the Ternary enumeration
    **/
    
    std::cout << "True = " << True << ", False = " << False << ", Unknown = " << Unknown << std::endl;
    
    if (True == true)
        std::cout << "True == true" << std::endl;
    
    if (True == false)
        std::cout << "True == false !!" << std::endl;
    
    if (Unknown == true)
        std::cout << "Unknown == true !!" << std::endl;
}