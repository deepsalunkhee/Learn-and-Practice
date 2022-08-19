#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50

typedef struct
{
    int a[MAX];
    int top;
} stack;
int isempty(stack *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
void push(stack *s, int ele)
{
    s->top++;
    s->a[s->top] = ele; // s1.[s1.top]=x  there is difference between s and s1.
}

int pop(stack *s)
{
    int x;

    x = s->a[s->top];
    s->top--;
    return x;
}

int importance(int x)
{
    switch (x)
    {
    case '(':
        return 0;

    case '+':
    case '-':
        return (1);
    case '*':
    case '/':
    case '%':
        return (2);

    default:
        return (0);
    }
}

int stack_top(stack *s)
{
    if (isempty(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        return s->a[s->top];
    }
}

int isoperand(char x)
{
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
        return 1;
    else
        return 0;
}

void convert(char infix[], char postfix[])
{
    stack s;
    s.top = -1;
    int i, k = 0, x, ele;

    for (i = 0; i < strlen(infix); i++)
    {

        x = infix[i];
        if (x == '(')
        {
            push(&s, x);
        }
        else if (x == ')')
        {
            while (1)
            {
                ele = pop(&s);
                if (ele == '(')
                    break;
                postfix[k++] = ele;
            }
        }
        else if (isoperand(x))
        {
            postfix[k++] = x;
        }
        else if (isempty(&s))
        {
            push(&s, x);
        }
        else if (importance(x) > importance(stack_top(&s)))
        {
            push(&s, x);
        }
        else
        {
            while ((isempty(&s) == 0) && (importance(x) <= importance(stack_top(&s))))
            {
                ele = pop(&s);
                postfix[k++] = x;
            }
            push(&s, x);
        }
    }
    while ((isempty(&s) == 0))
    {

        ele = pop(&s);
        postfix[k++] = x;
    }
    postfix[k] = '\0';
}

int main()
{
    char infix[50];
    char postfix[50];
    printf("enter the infix expression\n");
    gets(infix);
    convert(infix, postfix);
    printf("post fix is %s", postfix);
    return 0;
}