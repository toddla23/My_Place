#include <stdio.h>

int main(void)
{
    int X,num = 1;
    scanf("%d", &X);

    while(X > num)
    {
        X = X - num;
        num++;
    }

    if(num % 2 == 0)
    {
        printf("%d/%d", X, num+1-X);
    }
    else
    {
        printf("%d/%d", num+1-X, X);
    }

    return 0;
}
