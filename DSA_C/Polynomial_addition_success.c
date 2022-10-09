// Polynomial addition
// Deep Salunkhe
// SE CMPN A
// 21102A0014
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int c, e;
    struct node *next;
} node;
typedef struct LL
{
    node *start;
} LL;

void insert_end(LL *l, int cc, int ee)
{
    node *p, *newrec;
    newrec = (node *)malloc(sizeof(node));
    newrec->c = cc;
    newrec->e = ee;
    newrec->next = NULL;
    if (l->start == NULL)
        l->start = newrec;
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

void read(LL *l)
{
    int cc, ee, i, n;
    printf("enter the no of terms");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the coefficient and the exponent\n");
        scanf("%d%d", &cc, &ee);
        insert_end(l, cc, ee);
    }
}

void display(LL *l)
{
    node *p;
    if (l->start == NULL)
    {
        printf("No polynomial\n");
        return;
    }
    p = l->start;

    while (p != NULL)
    {
        printf("%dX^%d", p->c, p->e);
        p = p->next;
    }

    printf("\n");
}

void addpoly(LL *l1, LL *l2, LL *l3)
{
    node *p, *q;
    p = l1->start;
    q = l2->start;
    while (p != NULL && q != NULL)
    {
        if (p->e > q->e)
        {
            insert_end(l3, p->c, p->e);
            p = p->next;
        }
        else if (p->e < q->e)
        {
            insert_end(l3, q->c, q->e);
            q = q->next;
        }
        else
        {
            insert_end(l3, p->c + q->c, p->e);
            p = p->next;
            q = q->next;
        }
    }

    while (p != NULL)
    {
        insert_end(l3, p->c, p->e);
        p = p->next;
    }

    while (q != NULL)
    {
        insert_end(l3, q->c, q->e);
        q = q->next;
    }
}

int main()
{
    LL l1, l2, l3;
    l1.start = NULL;
    l3.start = NULL;
    l3.start = NULL;
    read(&l1);
    read(&l2);
    addpoly(&l1, &l2, &l3);
    printf("the sum is\n");
    display(&l3);
    return 0;
}
