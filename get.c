#include <stdio.h>
#include <stdlib.h>

#define N 99

int main(void)
{
	char c;
	int i = 0;
	int symbol = 0;
	int word = 0;
	int line = 0;
	char buf[N];

	while (1) {
		c = getchar();
//		printf("%d\n", c);
		if (c == EOF)
			break;
		if (c > 32) {
			symbol++;
			buf[i++] = c;
			continue;
		}
		if (c == 10) {
			line++;
		}
	}

	for (i = 0; buf[i] != '\0'; i++)
		putchar(buf[i]);

	printf("\nNumber of symbols = %d\n", symbol);
	printf("Number of words = %d\n", word);
	printf("Number of lines = %d\n", line);

	return 0;
}
