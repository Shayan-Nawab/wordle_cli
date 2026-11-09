FLAGS = -Wall -Wextra 

all: wordle

wordle: main.o input.o display.o words.o gamelogic.o
	gcc $(FLAGS) -o wordle main.o input.o display.o words.o gamelogic.o

main.o: main.c input.h display.h gamelogic.h words.h
	gcc $(FLAGS) -c main.c

input.o: input.c gamelogic.h words.h display.h
	gcc $(FLAGS) -c input.c

gamelogic.o: gamelogic.c display.h
	gcc $(FLAGS) -c gamelogic.c

display.o: display.c
	gcc $(FLAGS) -c display.c

words.o: words.c wordlist.inc
	gcc $(FLAGS) -c words.c

clean:
	rm -f wordle *.o
