#include <stdio.h>
#include <string.h>

int palindrome(char *s,  int length)
{
    char *ptr = s + length - 1; 

    for(int i = 0; i <length; i ++)
    {
        printf("%c, %c",s,ptr);
        if(ptr == s)
        {
            ptr--;
            s++;
            continue;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    char s[50];
    scanf("%s", s);

    printf("%s", s);

    printf("%d", strlen(s));

    if (palindrome(s, strlen(s)) == 0)
        printf("회문 입니다");
    else
        printf("회문 아님");


    return 0;
}ㅁㄴㅇ