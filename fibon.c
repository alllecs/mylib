#include <stdio.h>

int main(void)
{
	double i, j, k;
	double f, p;
	int ret;


	ret = scanf("Введите погрешность в формате 0.x %lf", &p);

	if (ret != 1)
		return 2;

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

		switch (p) {
			case 0.01:
				printf("Коэффициент 'золотого сечения' %.3f\n", f);
				break;
			case 0.001:
				printf("Коэффициент 'золотого сечения' %.4f\n", f);
				break;
			case 0.0001:
				printf("Коэффициент 'золотого сечения' %.5f\n", f);

		}
	}

	return 0;
}
