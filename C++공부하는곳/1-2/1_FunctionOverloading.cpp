#include <iostream>

void Myfunc(void)
{
    std::cout<<"Myfunc(void) called"<<std::endl;
}

void Myfunc(char c)
{
    std::cout<<"Myfunc(char c) called"<<std::endl;
}

void Myfunc(int a)
{
    std::cout<<"Myfunc(int a) called"<<std::endl;
}

int main(void)
{
    Myfunc();
    Myfunc('a'); // 이거 'a' 는 되는데 "a"는 왜 안됨??? 'a'는 문자상수니까 1칸이고 "a"는 문자열이니까 null문자가 뒤에 있어서 2칸임
    Myfunc(1);
    return 0;
}