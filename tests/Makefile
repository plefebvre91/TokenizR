CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -g -static-libstdc++
INCFLAG=-I../src/

test: ../src/tokenizer.cpp test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAG) $^ -o $@
	./run-test.sh

clean:
	rm ./test 2&>/dev/null
