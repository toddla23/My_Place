#include <cstdio>

int arr[50][50];
int M, N;

int check(int X,int Y)
{

    arr[X][Y] = 0;

    if(X + 1 < M && arr[X+1][Y] == 1) check(X+1,Y);
    if(X - 1 >= 0 && arr[X-1][Y] == 1) check(X-1,Y);
    if(Y + 1 < N && arr[X][Y+1] == 1) check(X,Y+1);
    if(Y - 1 >=0 && arr[X][Y-1] == 1) check(X,Y-1);
    return 0;
}

int main(void)
{
    int T, K, X, Y;
    int answer = 0;

    scanf("%d",&T);

    for(int i = 0; i < T; i++)
    {
        
        scanf("%d %d %d", &M, &N, &K);

        arr[50][50] = { 0,};

        while(K--)
        {
            scanf("%d %d", &X, &Y);
            arr[X][Y] = 1;
        }
        
        answer = 0;
        for(int i = 0; i < M; i ++)
        {
            for(int j = 0; j < N; j ++)
            {
                if(arr[i][j] == 1)
                {
                    check(i, j);
                    answer++;
                }

            }
        }

        printf("%d\n",answer);

    }

    return 0;
}
