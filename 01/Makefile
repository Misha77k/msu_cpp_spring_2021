CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: Allocator.o Allocator_test.o Allocator_main.o
	$(CC) $(FLAGS) Allocator.o Allocator_test.o Allocator_main.o -o Allocator

Allocator.o: Allocator.cpp
	$(CC) $(FLAGS) Allocator.cpp -c

Allocator_test.o: Allocator_test.cpp
	$(CC) $(FLAGS) Allocator_test.cpp -c

Allocator_main.o: Allocator_main.cpp
	$(CC) $(FLAGS) Allocator_main.cpp -c

test: Allocator.o Allocator_test.o Allocator_main.o
	$(CC) $(FLAGS) Allocator.o Allocator_test.o Allocator_main.o -o test
	./test

clean:
	rm -f *.o Allocator_main 	


