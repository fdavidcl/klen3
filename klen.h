/*

klen3
======================
An implementation of three-valued logic with the 3-element Kleene 
algebra (K3) in C++. It takes the values True, False and Unknown. 

Author: David Charte <fdavidcl@outlook.com>

License information:
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/
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
	constructor. We'll also allow converting native booleans to Klen
	objects.
	
*/
	Klen()              { *this = Unknown;          }
	Klen(const Klen& v) { *this = v;                }
	Klen(const bool& v) { *this = v ? True : False; }
	
	bool issame(Klen b) const { return value == b.value; }
	bool istrue()       const { return issame(True);     }
	bool isfalse()      const { return issame(False);    }
	bool isunknown()    const { return issame(Unknown);  }
	
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
	Let's implement comparison operators that are
	consistent with the structure we have here
*/
	Klen operator==(const Klen& b) const {
		if (isunknown() || b.isunknown())
			return Unknown;
		else if (issame(b))
			return True;
		else
			return False;
	}
	
	Klen operator!=(const Klen& b) const {
		return !(*this == b);
	}
	
/*
	Only True is considered truthy
	(and only False is considered falsy)
*/
	operator bool() const {
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