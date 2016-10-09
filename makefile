all: BDB

BDB: BDB.c
	gcc -o BDB BDB.c -I.

clean:
	rm BDB
