#include <stdio.h>

void binary(num)
{
    int a = 2;
    int n = 0;
    while(num > a)
    {
        n++;
    }
}

int main(void)
{
    int num;

    scanf("10진수 정수 입력 : %d", &num);

    binary(num);
}