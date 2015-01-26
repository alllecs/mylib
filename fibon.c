#include <stdio.h>

int main(void)
{
	double i, j, k;
	double f;

	j = 1;
	i = 1;
	printf("%.2f\n", i);
	printf("%.2f\n", j);
	while (j < 100) {
		k = i + j;
		i = j;
		j = k;

		if (j > 100)
			break;

		printf("%.2f\n", j);

		f = i / j;
		if ((f <= 0.7) || (f >= 0,6))
		printf("Коэффициент 'золотого сечения' %3.2f\n", f);
	}

	return 0;
}
