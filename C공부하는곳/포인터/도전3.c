#include <stdio.h>

int main(void)
{
    int arr[10];
    int num = 0;
    int *ptr1 = arr;
    int *ptr2 = arr + 10;
    
    for(int i = 0; i < 10; i++)
    {
        printf("입력:");
        scanf("%d", &num);

        if(num %2 != 0)
        {
            *ptr1 = num;
            ptr1++;
        }
        else
        {
            *ptr2 = num;
            ptr2--;
        }

        printf("출력 :");
        for(int i = 0; i <10; i++)
            printf(" %d",arr[i]);
    }  


    printf("배열요소의 출력 :");

    for(int i = 0; i <10; i++)
        printf(" %d",arr[i]);
}