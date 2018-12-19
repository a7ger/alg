CC = g++
STD = -std=c++17

a++ : main.o Parser.o PrintCommand.o
	$(CC) main.o Parser.o PrintCommand.o $(STD) -o a++
main.o : main.cpp
	$(CC) $(STD) -c main.cpp
Parser.o : Parser.cpp
	$(CC) $(STD) -c Parser.cpp
PrintCommand.o : PrintCommand.cpp
	$(CC) $(STD) -c PrintCommand.cpp
clean:
	rm *.o a++
r:
	./a++ main.alg
