#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct
{
    node *start;
} LL;

void insertbegining(LL *l, int ele)
{
    node *newrec;
    newrec = (node *)malloc(sizeof(node));
    newrec->data = ele;
    newrec->next = l->start;
    l->start = newrec;
}

void insertend(LL *l, int ele)
{
    node *newrec, *p;
    newrec = (node *)malloc(sizeof(node));
    newrec->data = ele;
    newrec->next = NULL;

    if (l->start == NULL)
        l->start = newrec;
    else
    {
        p = l->start;
        while (p->next != NULL)
            p = p->next;
        p->next = newrec;
    }
}

int count(LL *l)
{
    node *p;
    int c = 0;
    p = l->start;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }

    return c;
}

void insertAt(LL *l, int ele, int pos)
{
    node *newrec, *p;
    int i;

    newrec = (node *)malloc(sizeof(node));
    newrec->data = ele;
    if (pos > count(l) + 1)
    {
        printf("Invalid choice\n");
        return;
    }

    if (pos == 1)
    {
        newrec->next = l->start;
        l->start = newrec;
        return;
    }
    p = l->start;
    for (i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    newrec->next = p->next;
    p->next = newrec;
}

void display(LL *l)
{
    node *p;
    if (l->start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
        p = l->start;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
int deletebegining(LL *l)
{
    node *p;
    if (l->start == NULL)
        return -1;
    p = l->start;
    l->start = p->next;
    p->next = NULL;
    return p->data;
}

int deleteend(LL *l)
{
    node *p, *q;
    if (l->start == NULL)
        return -1;
    if (l->start->next == NULL)
    {
        p = l->start;
        l->start = NULL;
        return p->data;
    }
    else
    {
        while (q->next->next != NULL)
            q = q->next;
        p = q->next;
        q->next = NULL;
        return p->data;
    }
}

int deleteat(LL *l, int pos)
{
    node *p, *q;
    int i;

    if (pos == 1)
    {
        p = l->start;
        l->start = p->next;
        p->next = NULL;
        return p->data;
    }
    q = l->start;
    for (i = 1; i < pos - 1; i++)
        q = q->next;

    p = q->next;       //
    q->next = p->next; // check these lines
    p->next = NULL;    //
    return p->data;
}

void deleteelement(LL *l, int ele)
{
    node *p, *q;
    if (l->start == NULL)
    {
        printf("LL is empty\n");
        return;
    }
    if (l->start->data == ele)
    {
        p = l->start;
        l->start = p->next;
        p->next = NULL;
        return;
    }
    q = l->start;
    while (q->next != NULL)
    {
        if (ele == q->next->data)
            break;
        q = q->next;
    }
    p = q->next;

    if (p == NULL)
        printf("Element is not present\n");
    else
    {
        q->data = p->next;
        q->next - NULL;
    }
}
