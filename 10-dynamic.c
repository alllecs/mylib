#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256

char input[LINE][90];
/*
void main()
{
	get();

	int i, j;

	for (i = 0, j = 0; i < 5; i++) {
		gets(input);
		putchar(input[i]);
	}

}
*/
void main()
{
	char c;
	char *add[256];
	int i, j;
	int *a;

	i = 0;
	j = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t') {
			input[i][j] = c;
//			printf("%c", c);
			add[i] = &c;
			i++;
		}
		if (c == '\0') {
			j++;
		}
	}
	puts(*input);
}
