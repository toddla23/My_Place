#include <cstdio>

int main(void)
{
    int N, L;
    scanf("%d %d", &N, &L);

    
    while(true)
    {
        if (L%2 == 1 && N%(L/2) == 0) //L�� Ȧ���ϋ�
        {
            printf("Ȧ�� : %d\n", L);
            break;
        }
        else if (L % 2 == 0 && N%(L/2) == L/2)//L�� ¦���ϋ�
        {
            printf("¦�� : %d\n", L);
            break;
        }

        L++;

        if (L==N) //���� ������
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