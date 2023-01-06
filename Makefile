objects = build/core.o

all: $(objects)
	clang++ -g -Wall -std=c++20 $(objects) -o build/hello_world

build/core.o: src/core.cpp
	clang++ -Wall -std=c++20 -I . -c crypto/core.cpp -o build/core.o

clean:
	rm -rf build/*
