#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    char arr[N][N];

    for(int i = 0; i < N; i++)
        cin >> arr[i];


    int maxFriend = 0;

    for(int i = 0; i < N; i++)
    {
        char a[N];
        fill_n(a,N,'N');

        int temp = -1;
        for(int j = 0; j < N; j++)
        {
            if(j == i)
                continue;
            
            if(arr[i][j] == 'Y')
            {
                if(a[j] != 'Y')
                    a[j] = 'Y';

                for(int k = 0; k < N; k++)
                {
                    if(arr[j][k] == 'Y')
                    {
                        a[k] = 'Y';
                    }
                }
            }
        }

        for(int j = 0; j < N; j++)
            if(a[j] == 'Y')
                temp++;
                
        if(temp > maxFriend)
            maxFriend = temp;

    }

    cout << maxFriend;
}
