#include<iostream>
#include<cstdlib>
using namespace std;

int*** MakeArray3D(int *sz);
void destroyArray3D(int*** arr, int* sz);

int main(void)
{   
    int argc = 4;
    int argv[4] = {-1, 3, 4, 2};
    
    int i, dim = argc - 1; // argc = 2, dim = 1
    int *size = new int[dim];   // size = 크기 1의 1차원 배열

    for(i = 1; i < argc; i++)
        size[i-1] = argv[i]; //size ={2, 3}
    
    int ***arr3d = NULL;

    arr3d = MakeArray3D(size); // 주소값 받아옴

    for(int i = 0; i < size[0]; i++)
        for(int j = 0; j < size[1]; j++)
            for(int k = 0; k < size[2]; k++)
                arr3d[i][j][k] = (i*size[1] + j)*size[2] + k;
    
    for(int i = 0; i < size[0]; i++)
    {
        cout << "i :" << i << endl;
        for(int j = 0; j < size[1]; j++)
        {
            for(int k = 0; k < size[2]; k++)
                cout << arr3d[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }

    destroyArray3D(arr3d, size);

    return 0;
}

int*** MakeArray3D(int* sz)
{
    int n1 = sz[0];
    int n2 = sz[1];
    int n3 = sz[2];

    int ***arr = new int **[n1] ;
    for(int i = 0; i < n1; i++)
        arr[i] = new int *[n2];

    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n2; j++)
            arr[i][j] = new int [n3];
    
    return arr;
}

void destroyArray3D(int*** arr, int* sz)
{
    int n1 = sz[0];
    int n2 = sz[1];
    int n3 = sz[2];

    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n2; j++)
            delete[] arr[i][j];
    
    for(int i = 0; i < n1; i++)
        delete[] arr[i];

    delete[] arr;
}
