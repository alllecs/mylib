#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c;
	int n = 0;
	int i = 0;
	int k = 0;
	char buf[99];

	while ((c = getchar()) != EOF) {
		buf[i++] = c;
//		putchar(c);
		n++;
		if (c == '\n')
			k++;
	}


	for (i = 0;i < n; i++)
		putchar(buf[i]);

	printf("%d\n", n);
	printf("%d\n", k);
}
