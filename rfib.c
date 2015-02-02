#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonr(int n)
{
        if (n < 0) {
                printf("Введено отрицательное число\n");
                return 4;
        }
        if (n == 0) {
                printf("Введите число больше 0\n");
                return 3;
        }
        if (n == 1)
                return 1;

        if (n == 2)
                return 1;

        return (fibonr(n - 1) + fibonr(n - 2));
}

int main(int argc, char *argv[])
{
        int n;
        int ret;
        int m = 0;
        double f, p;

        if (argc != 2) {
                printf("Отсутствует или указано больше 1 аргумента\n");
                return 1;
        }

        ret = sscanf(argv[1], "%d", &n);

        if (ret != 1)
                return 2;

        if (n > 45) {
                printf("При n > 45 возможно переполнение\n");
                return 5;
        }

        printf("%d\n", fibonr(n));

        while (m < n) {
        f = (double)fibonr(n - 1) / (double) fibonr(n - 2);
        printf("f-1 = %d, f-2 = %d, f1/f2 = %.4f\n", fibonr(n - 1), fibonr(n - 2), f);
        m += 1;
        }

	return 0;
}
