#include <iostream>

int Adder(int a = 10, int b = 20)
{
    return a + b;
}

int main(void)
{
    std::cout<<Adder()<<std::endl;
    std::cout<<Adder(1)<<std::endl;
    std::cout<<Adder(1,2)<<std::endl;
}