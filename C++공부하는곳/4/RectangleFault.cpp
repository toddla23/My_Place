#include <iostream>
using namespace std;

class Point
{
public:
    int X;
    int Y;
};

class Ractangle
{
public:
    Point upleft;
    Point lowright;

public:
    void showracinfo()
    {
        cout<<"좌 상단: "<<'['<<upleft.X<<",";
        cout<<upleft.Y<<"]"<<endl;
        cout<<"우 하단: "<<'['<<lowright.X<<",";
        cout<<lowright.Y<<']'<<endl;
    }
};