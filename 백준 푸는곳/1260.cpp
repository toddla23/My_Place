#include <iostream>
using namespace std;
int roadlst[10000][2];

int DFS(int N, int M, int V)
{
    int visit = N+1;
 for(int i = 0; i < M; i++)      //경로탐색중 가장 숫자가 작은거 찾기
    {
        for(int j = 0; j < 2; j++)
        {
            if(roadlst[i][j] == V)
            {
                if(j == 1)
                {
                    if(visit > roadlst[i][0])
                    {
                        visit = roadlst[i][0];
                    }
                }
                else
                {
                    if(visit > roadlst[i][1])
                    {
                        visit = roadlst[i][1];
                    }
                }
            }
        }
    }
    return visit;
}

int main(void)
{
    int N, M, V;

    

    cin>> N >> M >> V;

    for(int i = 0; i < M; i ++)
    {
        int A, B;
        cin>> A >> B;
        roadlst[i][0] = A;
        roadlst[i][1] = B;
    }                       // 이차원 배열로 경로 저장

   DFS(N, M, V);


    int a;
    


}