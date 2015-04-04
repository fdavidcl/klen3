#include <iostream>

enum Ternary {
    /**************************************
        These values were chosen so that
        these properties are verified:
        
        True  ==  true
        False ==  false
        True  !=  false
        False !=  true
        NA    !=  true
        NA    !=  false
    **************************************/
    
    True = 1,
    False = 0,
    NA = -1
};

class Klen {
private:
    Ternary value;

public:
    
    Klen() :value(NA) {}
    
    Klen(Ternary v) { 
        *this = v; 
    }
    
    bool istrue()  { return value == True;  }
    bool isfalse() { return value == False; }
    bool isna()    { return value == NA;    }
    
    const Klen& operator=(const Klen& otro) {
        value = otro.value;
        return *this;
    }
    
    const Klen& operator=(const Ternary& valor) {
        value = valor;
        return *this;
    }
    
    const Klen& operator=(const bool& valor) {
        value = valor ? True : False;
        return *this;
    }
    
    Klen operator==(const Ternary& comp) {
        /********************************
        
        == |  T  | NA |  F
        ---------------------
        T  |  T  | NA |  F 
        NA | NA  | NA | NA
        F  |  F  | NA |  T
        
        ********************************/
        
        switch (value) {
            case True:
                if (comp == True) return True;
                else if (comp == NA) return NA;
                else return False;
                break;
            case False:
                if (comp == False) return True;
                else if (comp == NA) return NA;
                else return False;
                break;
            case NA:
                return NA;
                break;
            default:
                return NA;
        }
    }
    
    Klen operator==(const Klen& comp) {
        // Uses above (Klen == Ternary) comparison
        return *this == comp.value;
    }
    
    /*bool operator==(const bool& boolean) {
        return (*this == True && boolean) || (*this == False && !boolean);
    }*/
    
    operator Ternary() {
        return value;
    }
};

int main() {
    std::cout << "True = " << True << ", False = " << False << ", NA = " << NA << std::endl;
    
    if (True == true)
        std::cout << "True == true" << std::endl;
    
    if (True == false)
        std::cout << "True == false !!" << std::endl;
    
    if (NA == true)
        std::cout << "NA == true !!" << std::endl;
}