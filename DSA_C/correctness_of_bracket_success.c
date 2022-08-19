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

int isopeningbracket(char x)
{
    if (x == '{' || x == '(' || x == '[')
        return 1;
    else
        return 0;
}
int isclosingbracket(char x)
{
    if (x == '}' || x == ')' || x == ']')
        return 1;
    else
        return 0;
}

int checkit(char expression[])
{
    stack s;
    s.top = -1;
    int x, ele, i;
    for (i = 0; i < strlen(expression); i++)
    {
        if (isopeningbracket(expression[i]))
        {
            push(&s, expression[i]);
        }
        else if (isclosingbracket(expression[i]))
        {
            if (isempty(&s))
            {
                return 0;
            }
            else
            {
                ele = pop(&s);
                if ((expression[i] == ')') && (ele != '('))
                    return 0;
                if ((expression[i] == '}') && (ele != '{'))
                    return 0;
                if ((expression[i] == ']') && (ele != '['))
                    return 0;
            }
        }
    }

    if (isempty(&s))
        return 1;
    else
        return 0;
}

int main()
{
    char expression[50];
    printf("Enter the expression:\n");
    gets(expression);
    if (checkit(expression))
        printf("The expression is correct");
    else
        printf("The expression is incorrect");

    return 0;
}
