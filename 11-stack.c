/*
 * Лабораторная работа 11. Стек
 * http://bigor.bmstu.ru/?cnt/?doc=OP2/lab12new.aux/?cou=OP2/OP_P.cou
 *
 * Разработайте программу, которая читает из стандартного потока ввода слова
 * и размещает их в стек.
 * Перед добавлением в стек из слова удаляются все символы-не-буквы.
 * После завершения ввода слова из стека записываются в файл,
 * имя которого задается в командной строке.
 * Необходимо организовать грамотную работу с файлом.
 *
 * Максимальное число слов 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE 256
#define WORD 5

char *pointers[WORD];

char *in(char *input1)
{
	int stl;
	int i;
	int c;
	char *input;
	char *x;

	stl = strlen(input1);

	input = (char *)malloc(stl + 1);
	bzero(input, stl + 1);
	x = &input[0];

	for ( i = 0; i < stl && i < LINE; i++) {
		c = input1[i];
		if (isalpha(c)) {
			*x = c;
			x++;
		}
	}
	return input;
//	free(input);

}


void main(int argc, char *argv[])
{
	int i;
	char in1[LINE];
	FILE *fp;

	if (argc != 2) {
		printf("Отсутствует или указано больше 1 аргумента\n");
		exit(1);
	}

	fp = fopen(argv[1], "w");

	if (fp == NULL) {
		perror("Ошибка при работе с файлом");
		exit(1);
	}
/*
	while ((c = getchar()) != '\0') {
		*x = c;
	}
*/
	i = 0;
	while (i < WORD) {
		fgets(in1, LINE, stdin);
		pointers[i] = in(in1);
		i++;
	}
	i = 0;
	while (i < WORD) {
		fputs(pointers[i], fp);
		fputs("\n", fp);
		i++;
	}
	fclose(fp);
}
