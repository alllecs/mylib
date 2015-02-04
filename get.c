#include <stdio.h>

int main(void)
{
	int c;
	int n = 0;


	while ((c = getchar()) != EOF) {
		putchar(c);
		n++;
	}
	printf("%d\n", n - 1);
}
