#include <iostream>
using namespace std;

int angleClock(int H, int M);

int main(void)
{
int t;
int h, m;
    cin >> t;
    for(int i=0; i<t; i++)
{
        cin >> h >> m;
        cout << angleClock( h, m ) << endl;
    }
    return 0;
}
int angleClock(int H, int M)
{
    int angle;
        
    if (H*30 + 0.5*M < M*6)
    {   
        if(M*6 - (H*30 + 0.5*M) > 180)
            angle = 360 - (M*6 - (H*30 + 0.5*M));
        else
            angle =M*6 - (H*30 + 0.5*M);
    }
    else
    {   
        if(H*30 + 0.5*M - M*6 > 180)
            angle = 360 - (H*30 + 0.5*M - M*6);
        else
            angle = H*30 + 0.5*M - M*6;
    }
    
    return angle;
}