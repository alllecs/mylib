CC=gcc

CFLAGS=-W -Wall

all: time

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) time
