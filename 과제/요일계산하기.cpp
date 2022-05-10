#include <iostream>

using namespace std;

int check(int Year,int Month,int Day) 
{
    if (Month<3) 
   {
        Year -= 1;
        Month +=12;
    }
    return (Year + (Year/4) - (Year/100) + (Year/400) + (13*Month+8) /5 + Day) % 7;
}



int main(void)
{
    int t, Y, M, D;
    cin >> t; 

    for(int i = 0; i < t; i++)
    {
        cin >> Y >> M >> D;
        cout << check(Y, M, D) << endl;
    }

}