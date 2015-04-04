#include <iostream>

enum Ternary {
    /**************************************
        These values were chosen so that
        these properties are verified:
        
        True  ==  true
        False ==  false
        True  !=  false
        False !=  true
        Unknown    !=  true
        Unknown    !=  false
    **************************************/
    
    True = 1,
    False = 0,
    Unknown = -1
};

class Klen {
private:
    Ternary value;

public:
    
    Klen() :value(Unknown) {}
    
    Klen(Ternary v) { 
        *this = v; 
    }
    
    bool istrue()  { return value == True;  }
    bool isfalse() { return value == False; }
    bool isna()    { return value == Unknown;    }
    
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
        
        == |  T  | Unknown |  F
        ---------------------
        T  |  T  | Unknown |  F 
        Unknown | Unknown  | Unknown | Unknown
        F  |  F  | Unknown |  T
        
        ********************************/
        
        switch (value) {
            case True:
                if (comp == True) return True;
                else if (comp == Unknown) return Unknown;
                else return False;
                break;
            case False:
                if (comp == False) return True;
                else if (comp == Unknown) return Unknown;
                else return False;
                break;
            case Unknown:
                return Unknown;
                break;
            default:
                return Unknown;
        }
    }
    
    Klen operator==(const Klen& comp) {
        // Uses above (Klen == Ternary) comparison
        return *this == comp.value;
    }
    
    operator Ternary() {
        return value;
    }
};