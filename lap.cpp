#include<iostream>

using namespace std;



int main(void)
{
 
    int a = 0;
    int &b = a;

    b = b+1;

    cout << a <<endl;

}