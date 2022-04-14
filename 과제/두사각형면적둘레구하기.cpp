#include <iostream>
using namespace std;

int check(int a, int b, int c, int d)
{
    if(c < a)
    {
        int temp = a;
        a = c;
        c = temp;

        temp = d;
        d = b;
        b = temp;
    }

    int X;
    if(a < c)
    {
        if(b < c)
            X = 0;

        if(b > c && b < d)
            X = b - c;
        
        if(b > c && b > d)
            X = d - c;
    }

    return X;
}
void print(int px1, int py1, int qx1, int qy1, int px2, int py2, int qx2, int qy2)
{
    int x = check(px1, qx1, px2, qx2);
    int y = check(py1, qy1, py2, qy2);

    int round = 0, area = 0;

    int x1_length = qx1 - px1;
    int y1_length = qy1 - py1;
    int x2_length = qx2 - px2;
    int y2_length = qy2 - py2;

    round = (x1_length + y1_length + x2_length + y2_length - x - y ) * 2;
    area = (x1_length * y1_length) + (x2_length * y2_length) - (x*y);

    if(x == x2_length && y == y2_length)
    {
        round = (x1_length + y1_length) * 2;
        area = x1_length * y1_length ;
    }
    else if(x == 0 || y == 0)
    {
        round = (x1_length + y1_length + x2_length + y2_length) * 2;
        area = (x1_length * y1_length) + (x2_length * y2_length);
    }
    else
    {
        round = (x1_length + y1_length + x2_length + y2_length - x - y ) * 2;
        area = (x1_length * y1_length) + (x2_length * y2_length) - (x*y);
    }

    cout << area << " " << round << endl;
}

int main(void)
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int px1, py1, qx1, qy1;
        int px2, py2, qx2, qy2;
        cin >> px1 >> py1 >> qx1 >> qy1;
        cin >> px2 >> py2 >> qx2 >> qy2; 
   
        print(px1, py1, qx1, qy1, px2, py2, qx2, qy2);
        
    }

}