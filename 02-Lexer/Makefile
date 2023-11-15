all: main.exe

main.exe: main.o reconocedor_automata.o
	gcc -Wall -o main main.o reconocedor_automata.o

main.o: main.c
	gcc -c -Wall main.c

reconocedor_automata.o: reconocedor_automata.c
	gcc -c -Wall reconocedor_automata.c

clean:
	rm main.o
	rm reconocedor_automata.o