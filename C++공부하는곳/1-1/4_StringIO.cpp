#include <iostream>

int main(void)
{
    char name[100];
    char lang[200];
    std::cout<<"당신의 이름은?";
    std::cin>>name;

    std::cout<<"좋아하는 프로그래밍 언어는 무엇인가요? ";
    std::cin>>lang;

    std::cout<<"저의 이름은 "<<name<<"입니다. \n";
    std::cout<<"제일 좋아하는 언어는 "<<lang<<"입니다"<<std::endl;
    


}