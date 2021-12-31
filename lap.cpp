#include<iostream>


void swap(int &num1, int &num2)
{
    int a = num1;
    num1 = num2;
    num2 = a;
    printf("functions: %d, %d \n", num1, num2);

}

int main(void)
{
    int num1 = 10;
    int num2 = 20;
    swap(num1,num2);
    printf("%d, %d", num1, num2);
    return 0;
}