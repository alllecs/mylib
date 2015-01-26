CC=gcc

CFLAGS=-W -Wall -lm

all: time kor fibon

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) time kor fibon
