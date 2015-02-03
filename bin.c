#include <stdio.h>

int main()
{
    int  integral, binaryInt = 0, i = 1;
    float  binaryFract = 0, k =0.1f, fractional, temp1, binaryTotal, f;

    printf("***** Convert float to binary *******\n");
    printf("Enter float value : ");
    scanf("%f",&f);

    //Separating the integral value from the floating point variable
    integral = (int)f;

    //Separating the fractional value from the variable
    fractional = f - (int)f;

    //Loop for converting decimal to binary
    while(integral>0)
    {
        binaryInt = binaryInt + integral % 2 * i;
        i = i * 10;
        integral = integral / 2;
    }

    //Loop for converting Fractional value to binary
    while(k>0.00000001)
    {
        temp1 = fractional *2;
        binaryFract = binaryFract+((int)temp1)*k;
        fractional = temp1 - (int)temp1;
        k = k / 10;
    }

    //Combining both the integral and fractional binary value.
    binaryTotal = binaryInt +binaryFract;
    printf("binary equivalent = %lf\n", binaryTotal);
}
