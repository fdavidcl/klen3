/****************
Attempt of sanity 
****************/

#ifndef __KLEN
#define __KLEN

class Klen {
private:
	static const int T = 1;
	static const int F = 0;
	static const int U = -1;
	int value;
	
	Klen(int v) { value = v; }
	
public:
	static const Klen True;
	static const Klen False;
	static const Klen Unknown;
/*
	
	Any value in K3 must be equal to either True, False or Unknown.
	Thus, we only declare the default constructor and the copy 
	constructor.
	
*/
	Klen() { *this = Unknown; }
	Klen(const Klen& v) { value = v.value; }
	
	bool istrue()       { return value == T;       }
	bool isfalse()      { return value == F;       }
	bool isunknown()    { return value == U;       }
	bool issame(Klen b) { return value == b.value; }
};

const Klen Klen::True = Klen::T;
const Klen Klen::False = Klen::F;
const Klen Klen::Unknown = Klen::U;

namespace Kleene {
	const Klen True    = Klen::True;
	const Klen False   = Klen::False;
	const Klen Unknown = Klen::Unknown;
}

#endif