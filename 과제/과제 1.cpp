#include <iostream>
using namespace std;

int main(void)
{
    int t;

    cin>>t;

    int answer;

    for(int i = 0; i < t; i++)
    {   
        answer = 1;

        int n;
        cin >> n;

        for(int j = 0; j < n; j++)
        {
            int a = 0;
            cin >> a;
            a = a % 10;
            answer = (answer * a) % 10;
        }

        cout << answer <<endl;
    }


    return 0;
}