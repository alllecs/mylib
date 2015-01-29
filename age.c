#include <stdio.h>

int main(void)
{
	int i;
	int ret;

	printf("Введите возраст\n");
	ret = scanf("%d", &i);

//	if (ret != 1);
//		return 2;
	if(i < 1 || i > 100) {
		printf("Неправильно указан возраст\n");
		return 3;
	}

	printf("Ваш возраст %d\n", i);

	if (i < 18)
		printf("Вам до совершеннолетия %d\n", (18 - i));
	if (i > 18)
		printf("Вы совершеннолетний %d\n", (i - 18));
	if (i == 18)
		printf("Вы совершеннолетний\n");

	if (i < 60)
		printf("Вам до пенсии %d\n", (60 - i));
	if (i > 60)
		printf("Вы на пенсии %d\n", (i - 60));
	if (i == 60)
		printf("вы пенсионер\n");

	return 0;
}
