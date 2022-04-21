#include<iostream>
#include<cstdlib>
using namespace std;

int** makeArray(int* size)
{
    int** arr = new int* [size[0]];
    
    for(int i = 0; i < size[0]; i++)
        arr[i] = new int [size[1]];
    
    return arr;
}

void distroyArray(int** arr, int* size)
{
    for(int i = 0; i < size[0]; i++)
        delete[] arr[i];
    delete[] arr;
}

int main(void)
{
    int dim = 2;

    int* size = new int[dim];
    for(int i = 0; i < dim; i++)
        cin >> size[i];

    int** arr = NULL;
    
    arr = makeArray(size);
    
    for(int i = 0; i < size[0]; i ++)
        for(int j = 0; j < size[1]; j++)
            arr[i][j] = (size[1] * i) + j;

    for(int i = 0; i < size[0]; i ++)\
    {
        for(int j = 0; j < size[1]; j++)
            cout << arr[i][j] << " ";
        cout<<endl;
    }
        
    return 0;
}