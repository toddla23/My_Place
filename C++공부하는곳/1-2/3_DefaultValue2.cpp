#include <iostream>

int Adder(int a = 10, int b = 20); //함수 디폴트는 무조건 오른쪽에서 왼쪽으로 해야함
                                   // int Adder(int a = 10, int b ); 는 안된다는 거임 (함수의 인자가 왼쪽에서 오른쪽으로 채워지기 떄문에)


int main(void)
{
    std::cout<<Adder()<<std::endl;
    std::cout<<Adder(1)<<std::endl;
    std::cout<<Adder(1,2)<<std::endl;
}

int Adder(int a, int b)
{
    return a + b;
}