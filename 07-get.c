#include <stdio.h>
#include <stdlib.h>

#define N 99

int myspace(char a)
{
	if (a == ' ' || a == '\t' || a == '\n')
		return 1;
	return 0;
}

int main(void)
{
	char c;
	int i = 0;
	int symbol = 0;
	int word = 0;
	int line = 0;
	char buf[N];
	int s;

	s = 0;

	while (1) {
		c = getchar();
		if (c == EOF)
			break;
			symbol++;
			buf[i++] = c;

		if (c == 10) {
			line++;
		}

		if (s == 0) {
			if (myspace(c)) {
				s = 0;
			} else {
				s = 1;
			}

			continue;
		}
		if (s == 1) {
			word++;
			if (myspace(c)) {
				s = 0;
			} else {
				s = 2;
			}

			continue;
		}
		if (s == 2) {
			if (myspace(c)) {
				s = 0;
			} else {
				s = 2;
			}

			continue;
		}

	}

	for (i = 0; i <= symbol; i++)
		putchar(buf[i]);

	printf("\nNumber of symbols = %d\n", symbol);
	printf("Number of words = %d\n", word);
	printf("Number of lines = %d\n", line);

	return 0;
}
