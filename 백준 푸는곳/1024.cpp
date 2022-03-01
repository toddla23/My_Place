#include <cstdio>

int main(void)
{
    int N, L;
    scanf("%d %d", &N, &L);

    
    while(true)
    {
        if (L%2 == 1 && N%L == 0) //LÀÌ È¦¼öÀÏ‹š
        {
            break;
        }
        else if (L % 2 == 0 && N%L == L/2)//LÀÌ Â¦¼öÀÏ‹š
        {
            break;
        }

        L++;

    }


    if (L%2 == 0)
    {
        int a = -(N%L-1);

        if(N/L+a < 0)
        {
                printf("-1");
                return 0;
        }
        for(int i = 0; i < L; i++)
        {


            printf("%d ",N/L+a);
            a++;
            
            
        }
    }
    else if (L%2 == 1)
    {
        int a = -(L/2);

        if(N/L+a < 0)
        {
            printf("-1");
            return 0;
        }

        for(int i = 0; i < L; i++)
        {
            if(N/L+a < 0)
            {
                printf("-1");
                break;
            }
            printf("%d ",N/L+a);
            a++;
        }
    }

    return 0;

}