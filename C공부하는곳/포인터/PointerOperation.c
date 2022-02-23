#include <stdio.h>

int main(void)
{
    int num1 = 10;
    int * ptr = &num1;

    double num2 = 3.15;
    double *ptr2 = &num2;

    printf("%d", *ptr);
}
