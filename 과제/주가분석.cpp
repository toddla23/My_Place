#include <iostream>
using namespace std;

int main(void)
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n, a, b;
        int answer = 0;

        cin >> n >> a >> b;
        int c;
        for(int j = 0; j < n-2; j++)
        {   

            cin >> c;

            if (a < b)
            {
                if (b > c)
                {
                    answer ++;
                    a = b;
                    b = c;

                }
                else if (b == c)
                    continue;
                else
                {
                    a = b;
                    b = c;
                }
            }
            else
            { 
                a = b;
                b = c;
            }   
        }

        cout << answer << endl;
    }

    
}