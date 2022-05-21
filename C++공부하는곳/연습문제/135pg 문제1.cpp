#include <iostream>

using namespace std;

class Calculator
{
private:
    float num1, num2;
    int Opcount;

public:
    void init();
    float Add(float num1, float num2);
    float Mul(float num1, float num2);
    float Min(float num1, float num2);
    float Div(float num1, float num2);
    void ShowOpCount();
};

void Calculator::init()
{
    Opcount = 0;
}

float Calculator::Add(float num1, float num2)
{
    Opcount++;
    return num1 + num2;
}
float Calculator::Mul(float num1, float num2)
{
    Opcount++;
    return num1 * num2;
}
float Calculator::Min(float num1, float num2)
{
    Opcount++;
    return num1 - num2;
}
float Calculator::Div(float num1, float num2)
{
    Opcount++;
    return num1 / num2;
}

void Calculator::ShowOpCount()
{
    cout<< Opcount << endl;
}




int main(void)
{
    Calculator cal;
    cal.init();

    cout<<"3.2 + 2.4 = " << cal.Add(3.2, 2.4) <<endl;
    cout<<"3.5 / 1.7 = " << cal.Div(3.5, 1.7) <<endl;
    cout<<"2.2 + 1.5 = " << cal.Add(2.2, 1.5) <<endl;
    cout<<"4.9 / 1.2 = " << cal.Add(4.9, 1.2) <<endl;

    cal.ShowOpCount();

    return 0;
}