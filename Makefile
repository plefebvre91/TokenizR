CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

all: tokenizer

tokenizer: main.cpp tokenizer.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm tokenizer

#tokenize.o: tokenize.cpp
#	$(CC) $(CFLAGS) -c $^

#lib: tokenize.o
#	ar rvs $@ tkr.a
