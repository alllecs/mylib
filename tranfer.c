#include <stdio.h>
#include <math.h>

int main(void)
{
	int system, numb, rest;
	int i = 0;
	int k;
	int mass[99];
	double binnumb, bin;

	printf("Введите десятичное число\n");
	scanf("%lf", &binnumb);

	printf("Введите систему счисления\n");
	scanf("%d", &system);

	if (system < 2 || system > 16) {
		printf("Неправильно введена система счисления\n");
		return 3;
	}

	numb = (int)binnumb;
	bin = binnumb - (int)binnumb;

	if (numb >=1)
		while (numb > 0) {
			rest = numb % system;
			numb = numb / system;
			mass[i++] = rest;
	}

	for (k = i - 1; k > - 1; k--) {
		printf("%X", mass[k]);
	}
	printf(".");
	i = 0;
	if (bin < 1 && bin > 0) {
		rest = 0;
		while (bin > 0.0001) {
			if (bin >= 0.5) {
				bin = bin - 0.5;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;

			if (bin >= 0.25) {
				bin = bin - 0.25;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;

			if (bin >= 0.125) {
				bin = bin - 0.125;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;
			break;
		}

		for (i = 0; i < 3; i++) {
			printf("%X", mass[i]);
		}
	}

	printf("\n");
	return 0;
}
