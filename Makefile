cc = gcc
#CFLAGS = -std=c99 -O2 -pipe -march=native -Wall -Wpedantic -Wextra
PROGNAME = textedit
CFLAGS = -std=c99 -g -pipe -Wall -Wpedantic -Wextra

default:
	$(CC) $(CFLAGS) main.c -o $(PROGNAME) 
