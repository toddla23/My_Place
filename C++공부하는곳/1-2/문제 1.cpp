#include <iostream>

void swap(int *num1, int *num2)
{   
    int pnum = *num1; //pnum 에다가 num1이 가르키는 주소를 가진 변수의 내용물을 저장
    *num1 = *num2; //num1의 주소가 num2의 주소로 바뀜
    *num2 = pnum; //num2의 주소에 있는 변수의 내용을 pnum으로 바꿈

}

void swap(char *num1, char *num2)
{   
    char pnum = *num1;
    *num1 = *num2;
    *num2 = pnum;

}

void swap(double *num1, double *num2)
{   
    double pnum = *num1; 
    *num1 = *num2; 
    *num2 = pnum; 

}

int main(void)
{
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout<<num1<<' '<<num2<<std::endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout<<ch1<<' '<<ch2<<std::endl;

    double db1 = 20, db2 = 30;
    swap(&db1, &db2);
    std::cout<<db1<<' '<<db2<<std::endl;

}

//&연산은 주소값을 받아오는거고 *은 포인터가 가리키는 메모리 공간에 접근할때 사용