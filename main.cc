/*

Tests for klen.h

*/
#include <iostream>
#include "klen.h"
/*

This file consists only of a test function which will check
if a predicate evaluates as expected and, if not, output a message,
and the main function.

First, lets declare that we're using the values from Kleene's
algebra:

*/
using Kleene::True;
using Kleene::False;
using Kleene::Unknown;

void expect(Klen result, Klen pred) {
	if (!result.issame(pred))
		std::cout << "Error!!" << std::endl;
}

int main(int argc, char * argv[]) {
	expect(True, True);
	expect(False, False);
	expect(Unknown, Unknown);
	expect(True, true);
	expect(False, false);
	
/*
	Be careful! Operations with native booleans
	will return boolean values
*/
	expect(Unknown, True && Unknown);
	expect(False,   true && Unknown); // :(
	expect(False,   true == Unknown); // :(
	
	expect(Unknown, True == Unknown);
	expect(False,   True == False);
	expect(False,   False && Unknown);
	expect(True,    True || Unknown);
}