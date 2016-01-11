.PHONY: all test clean
CC=clang++
CFLAGS=-std=c++11 -Wall -Werror


test:
	$(CC) $(CFLAGS) -lpthread -lgtest test/test.cpp -o runtest

run : test
	./runtest

clean:
	rm runtest *.o
