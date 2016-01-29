CC=g++
CFLAGS=-Wall -Wextra

tokenizer: tokenizer.cpp
	$(CC) $(CFLAGS) $^ -o $@

