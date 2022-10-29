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

void enqueue(LL *l, int ele)
{
    node *newrec, *p;
    newrec = (node *)malloc(sizeof(node));
    newrec->data = ele;
    newrec->next = NULL;
    if (l->start == NULL)
    {
        l->start = newrec;
    }
    else
    {
        p = l->start;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newrec;
    }
}

int dequeue(LL *l)
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

int queuefront(LL *l)
{
    if (l->start == NULL)
        return -1;
    else
        return l->start->data;
}

int isempty(LL *l)
{
    if (l->start == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    LL q;

    q.start = NULL;
    int ch, ele;

    do
    {
        printf("\nMenu\n1. Enqueue.\n2. Dequeue\n3. Queue front\n4. Display.\n5.Exit.");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\nEnter the elements:");
            scanf("%d", &ele);
            enqueue(&q, ele);
            break;
        }
        case 2:
        {
            ele = dequeue(&q);
            if (isempty(&q))
            {
                printf("\nQueue is underflow.");
            }
            else
            {
                printf("%d is dequeue.", ele);
            }
            break;
        }
        case 3:
        {
            ele = queuefront(&q);
            if (ele == -1)
            {
                printf("\nQueue is underflow.");
            }
            else
            {
                printf("%d is at front.", ele);
            }
            break;
        }
        case 4:
        {
            display(&q);
            break;
        }
        case 5:
        {
            printf("\nExit satisfied.");
        }
        break;
        default:
        {
            printf("\nInvalid choice.");
        }
        }
    } while (ch != 5);
    return 0;
}



