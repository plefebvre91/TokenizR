CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -g -static-libstdc++

test: ../tokenizer.cpp test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./run-test.sh

clean:
	rm ./test 2&>/dev/null
