#include <stdio.h>

int main(void)
{
    char max = 0;
    char str[50];
    int idx = 0;

    scanf("%s", str);

    while(str[idx] != '\0')
    {
        if(max < str[idx])
            max = str[idx];
        
        idx ++;
    }

    printf("largest word : %c \n", max);

    return 0;
}