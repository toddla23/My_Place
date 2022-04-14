#include <iostream>
using namespace std;

void check(int a, int b, int c, int d)
{
    if(c < a)
    {
        int temp = a;
        a = c;
        c = temp;

        temp = d;
        d = b;
        b = temp;
    }

    int X,Y;
    if(a < c)
    {
        if(b < c)
        {
            X = 0;
            Y = (b - a) + (d - c);
        }

        if(b > c && b < d)
        {
            X = b - c;
            Y = d - a;
        }
        
        if(b > c && b > d)
        {
            X = d - c;
            Y = b - a;
        }

    }


    cout << X << " " << Y << endl;

}

int main(void)
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
   
        check(a, b, c, d);
        
    }

    
}