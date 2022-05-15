#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        char field[8][8];
        for(int j = 0; j < 8; j++)
            for(int k = 0; k < 8; k++)
                field[j][k] = '+';


        field[3][3] = 'O';
        field[4][4] = 'O';
        field[3][4] = 'X';
        field[4][3] = 'X';


        for(int j = 0; j < n; j++)
        {
            int x, y;
            cin >> y >> x;
            x = x-1;
            y = y-1;

            char e = 'X';
            if(j % 2 != 0)
                e = 'O';

            //cout << e << endl;
            //cout << "key:" << x << ", "<< y <<endl;

            int n = -1;
            for(int k = y + 1; k < 8; k++)
            {
                if(field[k][x] == '+')
                    break;
                if(field[k][x] == e)
                {
                    n = k;
                    //cout << "right:" << x << ", "<< k <<endl;
                    break;
                }
            }
            for(int k = y; k <= n && n != -1; k++)
            {
                field[k][x] = e;
                //cout << x << ", " << k <<endl;
            }

            n = -1;
            for(int k = y - 1; k > -1; k--)
            {
                if(field[k][x] == '+')
                    break;
                if(field[k][x] == e)
                {
                    n = k;
                    //cout << "left:" << x << ", "<< k <<endl;
                    break;
                }
            }
            for(int k = y; k > n && n != -1; k--)
            {
                field[k][x] = e;
                //cout << x << ", " << k <<endl;
            }

            n = -1;
            for(int k = x + 1; k < 8; k++)
            {
                if(field[y][k] == '+')
                    break;
                if(field[y][k] == e)
                {
                    n = k;
                    //cout << "down:" << x << ", "<< k <<endl;
                    break;
                }
            }
            for(int k = x; k < n && n != -1; k++)
            {
                field[y][k] = e;
                //cout << k << ", " << y <<endl;
            }

            n = -1;
            
            for(int k = x - 1; k > -1; k--)
            {
                if(field[y][k] == '+')
                    break;
                if(field[y][k] == e)
                {
                    n = k;
                    //cout << "up:" << x << ", "<< k <<endl;
                    break;
                }
            }
            for(int k = x; k > n && n != -1; k--)
            {
                field[y][k] = e;
                //cout << k << ", " << y <<endl;
            }

            int a = -1, b = -1;
            for(int X = x + 1, Y = y + 1; X < 8 && Y < 8; X++, Y++)
            {
                if(field[Y][X] == '+')
                    break;
                if(field[Y][X] == e)
                {
                    a = X;
                    b = Y;
                    //cout << "down right:" << a << ", " << b <<endl;
                    break;
                }
            }
            for(int X = x, Y = y; X < a && Y < b && a != -1; X++, Y++)
            {
                field[Y][X] = e;
                //cout << X << ", " << Y <<endl;
            }

            a = -1;
            b = -1;
            for(int X = x - 1, Y = y - 1; X > -1 && Y > -1; X--, Y--)
            {
                if(field[Y][X]  == '+')
                    break;
                if(field[Y][X] == e)
                {
                    a = X;
                    b = Y;
                    //cout << "up left:" << X << ", " << Y <<endl;
                    break;
                }
            }
            for(int X = x, Y = y; X > a && Y > b && a != -1; X--, Y--)
            {
                field[Y][X] = e;
                //cout << X << ", " << Y <<endl;
            }


            a = -1;
            b = -1;
            for(int X = x + 1, Y = y - 1; X < 8 && Y > -1; X++, Y--)
            {
                if(field[Y][X] == '+')
                    break;
                if(field[Y][X] == e)
                {
                    a = X;
                    b = Y;
                    //cout << "up right:" << X << ", " << Y <<endl;
                    break;
                }
            }
            for(int X = x, Y = y; X < a && Y > b && a != -1; X++, Y--)
            {
                field[Y][X] = e;
                //cout << X << ", " << Y <<endl;
            }

            a = -1;
            b = -1;
            for(int X = x - 1, Y = y + 1; X > -1 && Y < 8; X--, Y++)
            {
                if(field[Y][X] == '+')
                    break;
                if(field[Y][X] == e)
                {
                    a = X;
                    b = Y;
                    //cout << "down left:" << X << ", " << Y <<endl;
                    break;
                }
            }
            for(int X = x, Y = y; X > a && Y < b && a != -1; X--, Y++)
            {
                field[Y][X] = e;
                //cout << X << ", " << Y <<endl;
            }




            



            /*for(int j = 0; j < 8; j++)
            {
                for(int k = 0; k < 8; k++)
                    cout << field[j][k];
            
                cout << endl;
            }   */

        }
        
        int numX = 0,numO = 0;
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 8; k++)
            {
                if(field[j][k] == 'X')
                    numX++;
                else if(field[j][k] == 'O')
                    numO++;
            }
        }
        
        cout << numX << " " << numO << endl;
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 8; k++)
                cout << field[j][k];
            
            cout << endl;
        }
        
        
    }

}