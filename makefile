CC=gcc

CFLAGS=-W -Wall -lm

all: time kor

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) time kor
