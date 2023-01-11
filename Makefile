objects = build/bigint.o
tests = $(objects:%.o=%.test.o)

all: $(objects)
	clang++ -g -Wall -std=c++20 $(objects) -o build/crypto

run: clean all
	./build/crypto

build_tests: build/bigint.test.o
	clang++ -g -Wall -std=c++20 $(objects) $(tests) -o build/tests

run_tests: clean build_tests
	./build/tests

debug_tests: clean build_tests
	lldb ./build/tests


build/bigint.o: crypto/bigint.cpp crypto/bigint.hpp
	clang++ -g -Wall -std=c++20 -I . -c crypto/bigint.cpp -o build/bigint.o

build/bigint.test.o: build/bigint.o
	clang++ -g -Wall -std=c++20 -I . -c crypto/bigint.test.cpp -o build/bigint.test.o


clean:
	rm -rf build/*
