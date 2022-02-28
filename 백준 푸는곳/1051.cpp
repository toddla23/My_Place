#include <cstdio>

int main(void)
{
    int N, M, max;
    int arr[50][50];

    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &arr[i][j]); //%1d로 입력받으면 띄어쓰기 안하고도 하나씩 받을 수 있음
        }
    }

    int answer = 1;

    if(N > M)
    {
        max = M;
    }
    else
    {
        max = N;
    }  

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            
            for(int k = 1; k <= max; k++)
            {
                if(i+k < N && j+k < M && arr[i][j] == arr[i][j+k] && arr[i][j] == arr[i+k][j] && arr[i][j] == arr[i+k][j+k])
                {
                    if(answer < (k+1)*(k+1))
                    {
                        answer = (k+1)*(k+1);
                    }
                }
            }
        }
    }

    printf("%d", answer);
    return 0;
}