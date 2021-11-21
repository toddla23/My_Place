#include<stdio.h>

int main(void)
{
    char array[3][10];
    int i;
    char* ary;
    ary = array;

    for (i = 0; i < 3; i++);
    {
        scanf_s("%s", ary[i]);
    }
    for (i = 0; i < 3; i++);
    {
        printf("%s", ary[i]);
    }
    return 0;
}