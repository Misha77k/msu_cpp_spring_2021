CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: Allocator.o Allocator_test.o
	$(CC) $(FLAGS) Allocator.o Allocator_test.o -o Allocator

Allocator.o: Allocator.cpp
	$(CC) $(FLAGS) Allocator.cpp -c

Allocator_test.o: Allocator_test.cpp
	$(CC) $(FLAGS) Allocator_test.cpp -c

test: Allocator.o Allocator_test.o
	$(CC) $(FLAGS) Allocator.o Allocator_test.o -o test
	./test

clean:
	rm -f *.o Allocator_test

