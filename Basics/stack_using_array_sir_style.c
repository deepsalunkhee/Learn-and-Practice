// Implimentng stack using array

#include <stdio.h>
#define MAX 10

typedef struct
{
    int a[MAX];
    int top;
} stack;

void push(stack *s, int x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack over flow");
    }
    else
    {
        s->top++;
        s->a[s->top] = x;
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

int pop(stack *s)
{
    int x;
    if (isempty(s))
    {
        return -1;
    }
    else
    {
        x = s->a[s->top];
        s->top--;
        return x;
    }
}

int stack_top(stack *s)
{
    if (isempty(s))
    {
        return -1;
    }
    else
    {
        return s->a[s->top];
    }
}

void display(stack *s)
{
    int i;
    if (isempty(s))
    {
        printf("Stack under flow");
    }
    else
    {
        for (i = s->top; i >= 0; i--)
        {
            printf("%d\t", s->a[i]);
        }
    }
}

int main()
{
    stack *s1;
    int ch, element;
    s1->top = -1;
    do
    {
        printf("1:Push\n2:Pop\n3:Stacktop\n4:Display\n5:Exit\n");

        printf("Enter choice:\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("ENTER ELEMENT TO BE PUSHED:\n");
            scanf("%d", element);
            push(s1, element);
            break;
        case 2:
            element = pop(s1);
            if (element == -1)
            {
                printf("Stack underflow");
            }
            else
            {
                printf("element Poped=%d", element);
            }

            break;
        case 3:
            element = stack_top(s1);
            if (element == -1)
            {
                printf("Stack underflow");
            }
            else
            {
                printf("Stack top=%d", element);
            }
            break;
        case 4:
            display(s1);
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
