gcc_options = --std=c++17 -Wall -g

test_hashing : test_hashing.cpp hashing.hpp
	g++ $(gcc_options) -o $@ test_hashing.cpp

run : test_hashing
	./test_hashing

clean :
	rm -rf test_hashing

.PHONY : run clean