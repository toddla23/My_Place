#include <stdio.h>

int main(void)
{
    int A[2][2];
    int B[2][2];
    int C[2][2];

    printf("ù��° ����� 1�� �Է� : %d");
    scanf("%d %d", &A[0][0], &A[0][1]);

    printf("ù��° ����� 2�� �Է� : ");
    scanf("%d %d", &A[1][0], &A[1][1]);

    printf("�ι�° ����� 1�� �Է� : ");
    scanf("%d %d", &B[0][0], &B[0][1]);

    printf("�ι�° ����� 2�� �Է� : ");
    scanf("%d %d", &B[1][0], &B[1][1]);

    printf("�Է��� ù��° ��� : \n");

    for (int i = 0; i < 2; i++)
        printf("%d %d\n", A[i][0], A[i][1]);

    printf("�Է��� �ι�° ��� : \n");

    for (int j = 0; j < 2; j++)
        printf("%d %d\n", B[j][0], B[j][1]);

    printf("��ĳ����� ���� ����� : \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}