.PHONY: clean

all: tp2-pd tp2-forcabruta

tp2-forcabruta: bruteForce.cpp Makefile
	$(CXX) -O2 -std=c++11 $< -o $@

tp2-pd: dynamicProgramming.cpp Makefile
	$(CXX) -O2 -std=c++11 $< -o $@

clean:
	rm tp2-pd tp2-forcabruta
