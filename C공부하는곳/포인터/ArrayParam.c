#include <stdio.h>

void fct(int *age)
{

    *age += 1;
}

int main(void)
{
    int age = 10;

    fct(&age);

    printf("%d", age);
    
    return 0;
}