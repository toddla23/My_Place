#include <stdio.h>

int main(void)
{
    int arr[5];
    int sum = 0;
    
    for(int i = 0; i < 5; i ++)
    {
        scanf("%d", &arr[i]);
    }

    int max, min = arr[0];

    for(int i = 0; i < 5; i ++)
    {
        if(max < arr[i])
            max = arr[i];

        if(min > arr[i])
            min = arr[i];

        sum += arr[i];
    }

    printf("max of arr : %d \n", max);
    printf("min of arr : %d \n", min);
    printf("sum of arr : %d \n", sum);

    return 0;
}