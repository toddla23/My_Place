#include <stdio.h>

int main(void)
{
    int arr[10];
    int num = 0;
    int *ptr1 = arr;
    int *ptr2 = arr + 10;
    
    for(int i = 0; i < 10; i++)
    {
        printf("�Է�:");
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

        printf("��� :");
        for(int i = 0; i <10; i++)
            printf(" %d",arr[i]);
    }  


    printf("�迭����� ��� :");

    for(int i = 0; i <10; i++)
        printf(" %d",arr[i]);
}