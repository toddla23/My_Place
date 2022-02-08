#include <stdio.h>

int main(void)
{
    char str[50];
    int idx = 0;

    printf("input string : ");
    scanf("%s", str); // scanf할때 str앞에 &붙이면 안됨~~!
    printf("check string : %s \n", str);

    printf("output string with one word \n ");
    while(str[idx] != '\0')
    {
        printf("%c\n",str[idx]);
        idx++;
    }

    return 0;
}