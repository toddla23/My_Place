#include <iostream>
using namespace std;

void Round(int px1, int py1, int qx1, int qy1, int px2, int py2, int qx2, int qy2)
{
    //int px3 = 0, py3 = 0, qy3 = 0, qy3 = 0;

    if(px1 > qx2 || qx1 < px1 || py1 > qy2 || qy2 < py2)
        cout << "over lap" << endl;

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
   
        Round(px1, py1, qx1, qy1, px2, py2, qx2, qy2);
        
    }

    
}