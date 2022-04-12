#include <iostream>
using namespace std;

unsigned int check(unsigned int n)
{
    unsigned int x = 1;
        while(true)
        {
            if(n % 10 == 0)
                n = n / 10;
            else
            {
                x = x * (n % 10);
                n = n / 10;
            }

            if(n == 0)
            {
                n = x;
                break;
            }
        }


    return x;
}


int main(void)
{
    
    int t;
    unsigned int n;
    cin >>t;
    
    for(int i = 0; i < t; i++)
    {
        
        cin >> n;

        unsigned int x = n;

        while(x / 10 != 0)
        {
            x = check(x);

        }
        cout << x << endl;
    }
    

    return 0;
}