#include <stdio.h>
#include <math.h>

int main(void)
{
	int system, numb, rest;
	int i;
	int k;
	int mass[99];
	int ret;
	double binnumb, bin;

	printf("Введите десятичное число\n");
	ret = scanf("%lf", &binnumb);

	printf("Введите систему счисления\n");
	ret = scanf("%d", &system);

	if (system < 2 || system > 16) {
		printf("Неправильно введена система счисления\n");
		return 3;
	}

	if (ret != 1)
		return 2;

	numb = (int)binnumb;
	bin = binnumb - (int)binnumb;

	while (numb > 0) {
		if (bin < 1) {
			mass[i++] = 0;
			if (bin > 0.5) {
				bin = bin - 0.5;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;

			if (bin > 0.25) {
				bin = bin - 0.25;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;

			if (bin > 0.125) {
				bin = bin - 0.125;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;
		}
		if (numb > 1) {
			rest = numb % system;
			numb = numb / system;
			mass[i++] = rest;
		}
	}

	for (k = i - 1; k > - 1; k--) {
		printf("%X", mass[k]);
	}
	printf("\n");
	return 0;
}
