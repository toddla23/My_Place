#include <iostream>
using namespace std;

struct Car
{
    enum
    {
    ID_LEN  = 20,
    MAX_SPD = 200,
    FUEL_STEP   = 2,
    ACC_STEP    = 10,
    BEK_STEP    = 10
    };
    
    char gameID[ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState()
    {
        cout<<"소유자ID: "<<gameID<<endl;
        cout<<"연료량: "<<fuelGauge<<endl;
        cout<<"현재속도: "<<curSpeed<<endl;
    }

    void Accel()
    {
        if(fuelGauge <=0)
        return;
        else
        fuelGauge-=FUEL_STEP;

        if(curSpeed+ACC_STEP>=MAX_SPD)
        {
            curSpeed = MAX_SPD;
            return;
        }

        curSpeed += ACC_STEP;
    }

    void Break()
    {
        if(curSpeed <BEK_STEP)
        {
            curSpeed = 0;
            return;
        }
        curSpeed -= BEK_STEP;
    }
};



int main(void)
{
    Car run99 = {"run99", 100, 0}; //자바랑은 다르게 따로 초기화 선언을 안해도 순서대로 들어가나봄
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    return 0;

}