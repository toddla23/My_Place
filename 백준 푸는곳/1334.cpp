#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{

    int N = 0;
    cin >> N;
    
    int i = 1;
    while(true)
    {
        if(N/pow(10,i) < 1)
        {
            break;
        }
        i++;
    }

    cout << "i = " << i <<endl;

    int left, middle, right;

    if(i%2 == 0)
    {
        left = N /(pow(10,i/2));
        right = 

    }

    return 0;
}