#include <stdio.h>
#include <math.h>

int main(void)
{
	int system;
	int numb;
	int rest;
	int i, k;
	int mass[99];

	printf("Введите десятичное число\n");
	scanf("%d", &numb);

	printf("Введите систему счисления\n");
	scanf("%d", &system);

	while (numb > 0) {
		rest = numb % system;
		numb = numb / system;
		mass[i++] = rest;
	}
	for (k = i - 1; k > - 1; k--) {
		printf("%d", mass[k]);
	}
	printf("\n");
	return 0;

}
