#include<iostream>
using namespace std;

int main(void)
{
    int a = 5;
    double b = 3.14;

    int*c = &a;
    double* d = (double*)c;

    int e = a + b;

    cout << e  << endl;
    

    return 0;

}