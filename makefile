CC=gcc

CFLAGS=-W -Wall -lm

all: 02-time 03-kor 04-fibon 05-age 06-conversion 07-get

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) 02-time 03-kor 04-fibon 05-age 06-conversion 07-get
