#include <stdio.h>
#include <math.h>

int main(void)
{
	int system;
	int numb;
	int rest;
	int i, k;
	int mass[99];
	int ret;

	printf("Введите десятичное число\n");
	ret = scanf("%d", &numb);

	if (ret != 1)
		return 2;

	printf("Введите систему счисления\n");
	ret = scanf("%d", &system);

	if (ret != 1)
		return 2;

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
