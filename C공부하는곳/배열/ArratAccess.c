#include <stdio.h>

int main(void)
{
    int arr[5];
    int sum = 0;

    arr[0] = 10, arr[1] = 20, arr[2] = 30, arr[3] = 40, arr[4] = 50;
    
    for(int i = 0; i < 5; i++)
    {
        sum +=arr[i];
    };

    printf("sum of arr: %d \n", sum);
    printf("size of arr: %d \n", sizeof(arr));


    return 0;

}