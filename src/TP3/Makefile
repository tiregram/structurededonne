main : main.o contenu.o debug.o liste.o util.o
	gcc -Wall -pedantic -o main.bin main.o contenu.o debug.o liste.o util.o

main.o: main.c debug.h util.h contenu.h liste.h
	gcc -Wall -pedantic -c main.c

contenu.o : contenu.c contenu.h debug.h util.h
	gcc -Wall -pedantic -c contenu.c

debug.o : debug.c debug.h
	gcc -Wall -pedantic -c debug.c

util.o: util.c util.h
	gcc -Wall -pedantic -c util.c

liste.o: liste.c debug.h liste.h
	gcc -Wall -pedantic -c liste.c

clean:
	rm *.o;
	rm main.bin;
	@echo 'CLEAN OK'

all: main
	@echo 'BUILD OK'

rebuild:clean all
	@echo 'REBUILD OK'
