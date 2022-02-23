#include <stdio.h>

void odd(int *arr)
{
    printf("È¦¼ö :");
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
    printf("Â¦¼ö :");
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

    printf("ÃÑ 10°³ÀÇ ¼ýÀÚ ÀÔ·Â \n");

    for(int i = 0; i <10; i++)
    {
        printf("ÀÔ·Â : ");
        scanf("%d",&arr[i]);
    }

    odd(arr);
    even(arr);

}