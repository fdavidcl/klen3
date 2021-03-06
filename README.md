klen3
======================

An implementation of three-valued logic with the 3-element Kleene algebra (K3) 
in C++. It takes the values `True`, `False` and `Unknown`. 

* [What's a Kleene algebra?](https://en.wikipedia.org/wiki/De_Morgan_algebra#Kleene_algebra)
* [What's K3?](http://en.wikipedia.org/wiki/Many-valued_logic#Kleene_.28strong.29_K3_and_Priest_logic_P3)

## Usage

Just copy `klen.h` into your *includes* folder. Then, include it 
where you want to use it:

~~~c++
#include "klen.h"

using Kleene::True;
using Kleene::False;
using Kleene::Unknown;
~~~

## Examples

There are some examples and tests in `main.cc`.
