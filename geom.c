#include <stdio.h>

int main(void)
{
	int a, b, c;

	printf("Сторона а\n");
        if (scanf("%d", &a) != 1) {
                printf("Сторона а введна неверно!\n");
                return 2;
        }

	printf("Сторона b\n");
	if (scanf("%d", &b) != 1) {
		printf("Сторона b введна неверно!\n");
		return 3;
	}
	c = a * b;
	printf("Площадь прямоугольника %d\n", c);

	return 0;
}
