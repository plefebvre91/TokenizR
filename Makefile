CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -g

all: lib tokenizer

tokenizer: main.cpp tokenizer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

tokenizer.o: tokenizer.cpp
	$(CXX) tokenizer.cpp -c -std=c++11 -Wall -Wextra $^

lib: tokenizer.o
	ar rvcs libtkr.a $^

clean:
	rm tokenizer tokenizer.a 2&>/dev/null
