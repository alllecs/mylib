#include <stdio.h>

int main(void)
{
	int i, j, k;
	float f;

	j = 1;
	i = 1;
	printf("%d\n", i);
	printf("%d\n", j);
	while (j < 100) {
		k = i + j;
		i = j;
		j = k;

		if (j > 100)
			break;
		double f = (double) j / (double) i;
		printf("%3f\n", f);
		printf("%d\n", j);
	}

	return 0;
}
