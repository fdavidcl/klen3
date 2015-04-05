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
	
	bool issame(Klen b) const { return value == b.value; }
	bool istrue() const       { return issame(True);     }
	bool isfalse() const      { return issame(False);    }
	bool isunknown() const    { return issame(Unknown);  }
	
/*
	Now to our binary and unary operations: conjunction, 
	disjunction and 'not'
*/
	Klen operator&&(const Klen& b) const {
		if (isfalse() || b.isfalse())
			return False;
		else if (istrue() && b.istrue())
			return True;
		else
			return Unknown;
	}

	Klen operator||(const Klen& b) const {
		if (istrue() || b.istrue())
			return True;
		else if (isfalse() && b.isfalse())
			return False;
		else
			return Unknown;
	}
	
	Klen operator!() const {
		if (istrue()) return False;
		else if (isfalse()) return True;
		else return Unknown;
	}
	
/*
	Only True is considered truthy
	(and only False is considered falsy)
*/
	operator bool() {
		return istrue();
	}
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