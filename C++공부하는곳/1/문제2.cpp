#include <iostream>

int main(void)
{
    char name[100];
    char phone[100];

    std::cout<<"이름을 입력해 주세요~! \n";
    std::cin>>name;

    std::cout<<"전화번호를 입력해 주세요~! \n";
    std::cin>>phone;

    std::cout<<"이름 : "<<name<<std::endl;
    std::cout<<"전화번호 : "<<phone<<std::endl;


}