CPPFLAGS=-Wall

default: tests

tests: tests.cpp kleene.cpp
	$(CXX) -o $@ $< -I.