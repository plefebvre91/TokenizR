CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -O3 -static-libstdc++

all: tokenizer libtkr.so lib
	@echo "Program and libraries have been built successfully!"

tokenizer: src/tokenizer.cpp  src/main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

tokenizer.o: src/tokenizer.cpp
	$(CXX) $^ -c $(CXXFLAGS)

libtkr.so: src/tokenizer.cpp
	$(CXX) $(CXXFLAGS) $^ -shared -fPIC -o $@

lib: tokenizer.o libtkr.so
	@echo "Build static library..."
	@ar rvcs libtkr.a $^ >/dev/null
	@rm -rf lib 2>/dev/null
	@mkdir lib
	@mv libtkr.so libtkr.a ./lib
	@cp src/tokenizer.hpp ./lib

clean:
	@rm -rf lib tokenizer *.o 2>/dev/null
	@echo "Done."
