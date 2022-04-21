#include<iostream>
#include<cstdlib>
using namespace std;

int*** makeArray(int* size)
{
    int*** arr = new int** [size[0]];
    
    for(int i = 0; i < size[0]; i++)
        arr[i] = new int* [size[1]];


    for(int i = 0; i < size[0]; i++)
        for(int j = 0; j < size[1]; j++)
            arr[i][j] = new int [size[2]];
    
    return arr;
}

void distroyArray(int*** arr, int* size)
{
    for(int i = 0; i < size[0]; i++)
        for(int j = 0; j < size[1]; j++)
            delete[] arr[i][j];

    for(int i = 0; i < size[0]; i++)
        delete[] arr[i];
        
    delete[] arr;
}

int main(void)
{
    int dim = 3;

    int* size = new int[dim];
    for(int i = 0; i < dim; i++)
        cin >> size[i];

    int*** arr = NULL;
    
    arr = makeArray(size);
    
    for(int i = 0; i < size[0]; i ++)
        for(int j = 0; j < size[1]; j++)
            for(int k = 0; k < size[2]; k++)
                arr[i][j][k] = (i*size[1] + j)*size[2] + k;

    for(int i = 0; i < size[0]; i++)
    {
        cout << "i :" << i << endl;
        for(int j = 0; j < size[1]; j++)
        {
            for(int k = 0; k < size[2]; k++)
                cout << arr[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }
        
    return 0;
}