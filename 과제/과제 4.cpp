#include <iostream>
using namespace std;


int main(void)
{
    int t;

    cin>>t;


    for(int i = 0; i < t; i++)
    {   
        int n;
        cin >> n;

        int answer = 0;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;

            answer += a;
        }

        cout << answer <<endl;
    }


    return 0;
}