#include <iostream>
#include <vector>

using namespace std;

int MatrixMultiplication(vector<vector<int>> A, vector<vector<int>> B, int r, int s, int t)
{
    vector<vector<int>>answer(r,vector<int>(t));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < t; j++)
        {
            int n = 0;
            for(int k = 0; k < s; k++)
                n = n + A[i][k] * B[k][j];
        
            answer[i][j] = n;
        }
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < t; j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }

}

int main(void)
{
    int a;
    cin >> a;

    for(int i = 0; i < a; i++)
    {
        int r,s,t;

        cin >> r >> s >> t;

        vector<vector<int>>A(r,vector<int>(s));
        vector<vector<int>>B(s,vector<int>(t));

        for(int j = 0; j < r; j++)
            for(int k = 0; k < s; k++)
                cin >> A[j][k];

        for(int j = 0; j < s; j++)
            for(int k = 0; k < t; k++)
                cin >> B[j][k];
        
        MatrixMultiplication(A, B, r, s, t);


    }

}