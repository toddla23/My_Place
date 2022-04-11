#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct 
{
    char data[SIZE];
    int top;
}StackType;

void init(StackType* S)
{
    S->top = -1;
}

int isEmpty(StackType* S)
{
    return S->top == -1;

}

int isFull(StackType* S)
{
    return S->top == SIZE - 1;
}

void push(StackType* S, char c)
{
    if(isFull(S))
         printf("Over Flow!! \n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
    
}

char pop(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Under Flow!! \n");
        return -1;
    }

    char e = S->data[S->top];
    S->top--;
    return e;
}

char peek(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Under Flow!! \n");
        return -1;
    }

    return S->data[S->top];
}

void print(StackType* S)
{
    for(int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

int evaluate(char postfix[])
{
    StackType S;
    init(&S);

    int op1, op2, value;
    char c;
    int n = strlen(postfix);

    for(int i = 0; i < n; i++)
    {
        c = postfix[i];

        if(c != '+' && c != '-' && c != '*' && c != '/')
        {
            value = c - '0';
            push(&S, value);
        }
        else
        {
            op2 = pop(&S);
            op1 = pop(&S);
            switch(c)
            {
                case '+':
                    push(&S, op1+op2);
                    break;

                case '-':
                    push(&S, op1-op2);
                    break;

                case '*':
                    push(&S, op1*op2);
                    break;

                case '/':
                    push(&S, op1/op2);
                    break;
            }
        }
    }

}

int main(void)
{
    char exp[SIZE];
    scanf("%s", exp);

    printf("%d\n", evaluate(exp));

    return 0;
}