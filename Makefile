CC = g++
STD = -std=c++17

a++ : main.o
	$(CC) main.o $(STD) -o a++
main.o : main.cpp
	$(CC) $(STD) -c main.cpp
clean:
	rm *.o a++
r:
	./a++ main.alg
