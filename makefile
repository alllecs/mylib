CC=gcc

CFLAGS=-W -Wall -lm

all: time kor fibon age

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) time kor fibon age
