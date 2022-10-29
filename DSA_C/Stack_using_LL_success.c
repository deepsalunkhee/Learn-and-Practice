//Deep Salunkhe
//21101A0014
//SE CMPN A
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct LL
{
    node *start;
} LL;

void push(LL *l, int ele)
{
    node *newrec;
    newrec = (node *)malloc(sizeof(node));
    newrec->data = ele;
    newrec->next = l->start;
    l->start = newrec;
}

void display(LL *l)
{
    node *p;
    if (l->start == NULL)
    {
        printf("\nLinkList is Empty.");
    }
    else
    {
        p = l->start;
        while (p != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
int pop(LL *l)
{
    node *p;
    if (l->start == NULL)
    {
        return -1;
    }
    p = l->start;
    l->start = l->start->next;

    return p->data;
}

int stack_top(LL *l)
{
    if (l->start == NULL)
        return -1;
    else
        return l->start->data;
}

int main()
{

    LL s1;
    s1.start = NULL;
    int ch, ele;

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