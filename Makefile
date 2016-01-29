CC=g++
CFLAGS=-Wall -Wextra

all: tokenizer

tokenizer: tokenizer.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm tokenizer

#tokenize.o: tokenize.cpp
#	$(CC) $(CFLAGS) -c $^

#lib: tokenize.o
#	ar rvs $@ tkr.a
