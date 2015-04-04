CPPFLAGS=-Wall
EXE=$(basename $(wildcard *.cc, *.cpp))
default: $(EXE)