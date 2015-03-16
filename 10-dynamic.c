#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256

void main()
{

	int i, j;
	char input1[LINE];
	char input2[LINE];
	char c;

	j = 0;
	gets(input1);
	for (i = 0; j < strlen(input1); i++) {
		c = input1[i];
		if (c != ' ' && c != '\t') {
			input2[j] = c;
			j++;
		}
	}

		puts(input2);
}
