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

        

        int X;
        cin >> X;

        int max = X;
        int min = X;

        for(int j = 0; j < n-1; j++)
        {
            int a;
            cin >> a;

            if(max < a)
                max = a;
            
            if(min > a)
                min = a;
        }

        cout << max << " " << min <<endl;
    }


    return 0;
}