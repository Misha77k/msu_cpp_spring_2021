CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: BigInt.o BigInt_main.o
	$(CC) $(FLAGS) BigInt.o BigInt_main.o -o BigInt

BigInt.o: BigInt.cpp
	$(CC) $(FLAGS) BigInt.cpp -c

BigInt_main.o: BigInt_main.cpp
	$(CC) $(FLAGS) BigInt_main.cpp -c

test: BigInt.o BigInt_main.o
	$(CC) $(FLAGS) BigInt.o BigInt_main.o -o test
	./test

clean:
	rm -f *.o BigInt_main

