CPPFLAGS=-Wall
EXE=main

default: $(EXE)

$(EXE): $(EXE).cc klen.h
	$(CXX) -o $@ $< -I.
	
clean:
	rm -f $(EXE)