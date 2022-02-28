#include <cstdio>

int main(void)
{
    int N, L;
    scanf("%d %d", &N, &L);

    
    while(true)
    {
        if (L%2 == 1 && N%(L/2) == 0) //L이 홀수일떄
        {
            printf("홀수 : %d\n", L);
            break;
        }
        else if (L % 2 == 0 && N%(L/2) == L/2)//L이 짝수일떄
        {
            printf("짝수 : %d\n", L);
            break;
        }

        L++;

        if (L==N) //답이 없을떄
        {
            L = -1;
            break;
        }
    }


    for(int i = -(L-1)/2 ; i < (L-1)/2 + 1; i++)
    {
        printf("%d ", N/L + i);
    }

    return 0;

}