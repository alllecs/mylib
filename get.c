#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c;
	int i = 0;
	int symbol = 0;
	int word = 0;
	int line = 0;
	char buf[99];

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '	' || c == '\n') {
			word++;
			if (c == '\n')
				line++;
			c = '\n';
		}
		buf[i++] = c;

		symbol++;
	}


	for (i = 0; i < symbol; i++)
		putchar(buf[i]);

	printf("\nNumber of symbols = %d\n", symbol);
	printf("Number of words = %d\n", word);
	printf("Number of lines = %d\n", line);

	return 0;
}
