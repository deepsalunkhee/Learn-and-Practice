#include <stdio.h>

#include <string.h>
#define MAX 50

typedef struct
{
    char a[MAX];
    int top;
} stack;

void push(stack *s, char ele)
{
    s->top++;
    s->a[s->top] = ele;
}

int pop(stack *s)
{
    char x;
    x = s->a[s->top];
    s->top--;
    return x;
}

int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int isoperand(char x)
{
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
        return 1;
    else
        return 0;
}

int isoperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
        return 1;
    else
        return 0;
}
char stack_top(stack *s)
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

int postfixevalute(char postfix[])
{
    stack s;
    s.top = -1;
    int i, op1, op2, v;
    char x;

    for (i = 0; i < strlen(postfix); i++)
    {
        if (isoperand(postfix[i]))
        {
            push(&s, (int)postfix[i] - '0');
        }
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);

            switch (postfix[i])
            {

            case '+':
                v = op1 + op2;
                break;
            case '-':
                v = op2 - op1;
                break;
            case '*':
                v = op1 * op2;
                break;
            case '/':
                v = op2 / op1;
                break;
            case '%':
                v = op1 % op2;
                break;
            default:
                return 0;
            }
            push(&s, v);
        }
    }

    return pop(&s);
}

int main()
{
    stack s;
    s.top = -1;
    char postfix[50];
    int k;

    printf("enter the post fix expression:\n");
    gets(postfix);
    k = postfixevalute(postfix);

    printf("the value of that expression is:%d", k);
    return 0;
}