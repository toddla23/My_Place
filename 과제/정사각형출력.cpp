#include <iostream>
using namespace std;

void print(int n)
{

    int mid = n/2+1;

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if(i == mid && j == mid)
                cout <<"*";
            else if((j == 1 || j == mid || j == n) &&(i == 1 || i == mid || i == n))
                cout << "+";
            else if ((j != 1 || j != mid || j != n) &&(i == 1 || i == mid || i == n))
                cout << "-";
            else if((j == 1 || j == mid || j == n) &&(i != 1 || i != mid || i != n))
                cout << "|";

            else if(i == j)
                cout << "\\";
            else if (n - i + 1 == j)
                cout << "/";
            else if (i == n - j + 1)
                cout << "/";
            else
                cout << ".";
        }
        cout << "\n";
    }
}

int main(void)
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        print(n);
        
    }

    
}