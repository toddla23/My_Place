#include <stdio.h>

void odd(int *arr)
{
    printf("Ȧ�� :");
    for(int i = 0; i <10; i ++)
    {
        if(arr[i] % 2 != 0){
            printf("%d",arr[i]);
        }
    }
    printf("\n");
}


void even(int *arr)
{
    printf("¦�� :");
    for(int i = 0; i <10; i ++)
    {
        if(arr[i] % 2 == 0)
        {
            printf("%d",arr[i]);
        }
    }
    printf("\n");
}


int main(void)
{
    int arr[10];

    printf("�� 10���� ���� �Է� \n");

    for(int i = 0; i <10; i++)
    {
        printf("�Է� : ");
        scanf("%d",&arr[i]);
    }

    odd(arr);
    even(arr);

}