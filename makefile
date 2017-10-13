CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)

HM : main.o hangman.o
	$(CC) -o $@ main.o hangman.o

main.o : main.cpp main.h
	$(CC) $(CFLAGS) main.cpp -o $@

hangman.o : hangman.cpp hangman.h
	$(CC) $(CFLAGS) hangman.cpp -o $@


clean:
	rm *.o
	rm HM
