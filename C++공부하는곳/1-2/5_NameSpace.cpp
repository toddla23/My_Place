#include <iostream>

namespace BestComImpl
{
    void simpleFunc(void);
    
}
namespace BestComImpl
{
    void prettyFunc(void);
    
}

namespace ProgComImpl
{
    void simpleFunc(void);
}

int main(void)
{
    BestComImpl::simpleFunc();
    return 0;
}

void BestComImpl::simpleFunc(void)
{
    std::cout<<"BestCom이 정의 한 함수"<<std::endl;
    prettyFunc();
    ProgComImpl::simpleFunc();
}

void BestComImpl::prettyFunc(void)
{
    std::cout<<"So pretty!"<<std::endl;
}

void ProgComImpl::simpleFunc(void)
{
    std::cout<<"ProgCom이 정의 한 함수"<<std::endl;

}