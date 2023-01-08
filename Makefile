objects = build/bigint.o
tests = $(objects:%.o=%.test.o)

all: $(objects)
	clang++ -g -Wall -std=c++20 $(objects) -o build/crypto

build_tests: build/bigint.test.o
	clang++ -g -Wall -std=c++20 $(objects) $(tests) -o build/tests

run_tests: build_tests
	./build/tests

build/bigint.o: crypto/bigint.cpp crypto/bigint.hpp
	clang++ -Wall -std=c++20 -I . -c crypto/bigint.cpp -o build/bigint.o

build/bigint.test.o: build/bigint.o
	clang++ -Wall -std=c++20 -I . -c crypto/bigint.test.cpp -o build/bigint.test.o


clean:
	rm -rf build/*
