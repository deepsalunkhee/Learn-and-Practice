// Implimentng stack using array

#include <stdio.h>
#define MAX 10

typedef struct
{
    int a[MAX];
    int top;
} stack;

void push(stack *s, int ele)
{

    if (s->top == MAX - 1)
    {
        printf("Stack over flow\n");
    }
    else
    {

        s->top++;
        s->a[s->top] = ele; // s1.[s1.top]=x  there is difference between s and s1.
    }
}

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

void pop(stack *s)
{
    int x;
    if (isempty(s))
    {

        printf("Stack underflow\n");
    }
    else
    {
        x = s->a[s->top];
        s->top--;
        printf("element Poped=%d", x);
    }
}

void stack_top(stack *s)
{
    if (isempty(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Stack top=%d\n", s->a[s->top]);
    }
}

void display(stack *s)
{
    int i;
    if (isempty(s))
    {
        printf("Stack under flow\n");
    }
    else
    {
        for (i = s->top; i >= 0; i--)
        {
            printf("|_%d_|\n", s->a[i]);
        }
    }
}

int main()
{
    stack s1;
    int ch, ele;
    s1.top = -1;
    do
    {
        printf("1:Push\n2:Pop\n3:Stacktop\n4:Display\n5:Exit\n");

        printf("Enter choice:\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("ENTER ELEMENT TO BE PUSHED:\n");
            scanf("%d", &ele);
            push(&s1, ele);
            break;

        case 2:
            pop(&s1);
            break;
        case 3:
            stack_top(&s1);
            break;
        case 4:
            display(&s1);
            break;
        case 5:
            printf("exit satisfied\n");
            break;
        default:
            printf("Invaiid choice");
            break;
        }

    } while (ch != 5);

    return 0;
}