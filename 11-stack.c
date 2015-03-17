/* [Ссылка]( http://bigor.bmstu.ru/?cnt/?doc=OP2/lab12new.aux/?cou=OP2/OP_P.cou )
Разработайте программу, которая читает из стандартного потока ввода слова и размещает их в стек. Перед добавлением в стек из слова удаляются все символы-не-буквы. После завершения ввода слова из стека записываются в файл, имя которого задается в командной строке. Необходимо организовать грамотную работу с файлом.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256

void main(int argc, char *argv[])
{
	char in1[LINE];
	char c;
	char stl;
	char *x;
	int i;
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

	fgets(in1, LINE, stdin);
	x = &in1[0];
	stl = strlen(in1);

	for (i = 0; i < stl; i++) {
		c = in1[i];
		if (c >= 65 && c <= 122) {
			*x = c;
			x++;
		}
	}
	fputs(in1, fp);

	fclose(fp);
}
