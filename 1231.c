#include <stdio.h>



void main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d��° �л��� �̸��� �Է��Ͻÿ� : ", i + 1);
        scanf("%s", &p[i].name);
        printf("%d��° �л��� �⸻���� ������ �Է��Ͻÿ� : ", i + 1);
        scanf("%d", &p[i].score);
    }
    int mins;
    int maxs;

    int max = 0;
    int min = 100;
    for (int i = 0; i < 5; i++)
    {


        if (p[i].score > max)
        {
            maxs = i;
            max = p[i].score;
        }

        if (p[i].score < min)
        {
            mins = i;
            min = p[i].score;
        }
    }

}