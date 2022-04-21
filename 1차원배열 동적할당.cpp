#include<iostream>
#include<cstdlib>
using namespace std;

int* makeArray(int* size)
{
    int* arr = new int [size[0]];
    
    return arr;
}

void distroyArray(int* arr)
{
    delete[] arr;
}

int main(void)
{
    int dim = 1;

    int* size = new int[dim];
    for(int i = 0; i < dim; i++)
        cin >> size[i];

    int* arr = NULL;
    
    arr = makeArray(size);
    
    for(int i = 0; i < size[0]; i ++)
        arr[i] = i;

    for(int i = 0; i < size[0]; i ++)
        cout << arr[i] << " ";

    return 0;
}