#include <stdio.h>

int main(void)
{
    int L = 3 / 10;

    int y = 0;
    int* x = &y;

    *x = 3;
    
    printf("%d", y);
}
