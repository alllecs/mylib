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
typedef struct node_t TNode;

typedef struct node_t {
	TNode *pre;
	char *text;
} TNode;

typedef struct stack_t TStack;

typedef struct stack_t {
	int number;
	TNode *top;
} TStack;

void print(TStack *stack, FILE *fp)
{
	TNode *node;
	int i = 1;

	node = stack->top;
	while (node) {
//		printf("%d: %s\n", i, node->text);
		fputs(node->text, fp);
		fputs("\n", fp);
		node = node->pre;
		i++;

	}
}

TStack *Create(void)
{
	TStack *t;

	t = malloc(sizeof(TStack));
	t->number = 0;
	t->top = NULL;

	return t;

}

void Push(TStack *stack, char *text)
{
	TNode *node = malloc(sizeof(TNode));
	node->pre = stack->top;
	stack->top = node;
	node->text = strdup(text);
	stack->number++;
}

char *Pop(TStack *stack)
{
	TNode *node;
	node = stack->top;
	if (node) {
		char *t;
		stack->top = node->pre;
		stack->number--;
		t = node->text;
		free(node);
		return t;
	}

	free(t);
	return NULL;
}

void Clear(TStack *stack)
{
	while (stack->top != NULL) {
		Pop(stack);
	}
}

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
}


int main(int argc, char *argv[])
{
	int i;
	char ln1[LINE];
	FILE *fp;

	TStack *stack = NULL;

	if (argc != 2) {
		printf("Отсутствует или указано больше 1 аргумента\n");
		exit(1);
	}

	fp = fopen(argv[1], "w");

	if (fp == NULL) {
		perror("Ошибка при работе с файлом");
		exit(1);
	}

	stack =  Create();
	i = 0;

	while (i < WORD) {
		fgets(ln1, LINE, stdin);
		Push(stack, in(ln1));
		i++;
	}

	print(stack, fp);

	Clear(stack);

	fclose(fp);

	return 0;
}
