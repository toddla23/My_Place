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
        cout<<"�� ���: "<<'['<<upleft.X<<",";
        cout<<upleft.Y<<"]"<<endl;
        cout<<"�� �ϴ�: "<<'['<<lowright.X<<",";
        cout<<lowright.Y<<']'<<endl;
    }
};