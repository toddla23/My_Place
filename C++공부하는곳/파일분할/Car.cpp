#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char* ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    
}