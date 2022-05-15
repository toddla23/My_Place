#include <iostream>
#include <fstream>
using namespace std;


void magicSquare(int n)
{
    int square[n][n];

    int x = n/2;
    int y = 0;

    for(int i = 0; i < n*n; i++)
    {
        square[y][x] = i;

        x = (x + n - 1) % n;
        y = (y + n - 1) % n;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d", square[i][j]);
        printf("\n");
    }
}


int main(void)
{
    int line;
    ifstream file;

    file.open("input.txt");

    int num;
    file >> num;
    printf("%d", num);

    
    for(int i = 0; i < num; i++)
    {
        int n;
        file >> n;
        magicSquare(n);    
    }

    return 0;
}