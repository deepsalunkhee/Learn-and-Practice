// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int data;
//     struct node *next;
// } node;

// typedef struct
// {
//     node *start;
// } LL;

// void insertbegining(LL *l, int ele)
// {
//     node *newrec;
//     newrec = (node *)malloc(sizeof(node));
//     newrec->data = ele;
//     newrec->next = l->start;
//     l->start = newrec;
// }

// void insertend(LL *l, int ele)
// {
//     node *newrec, *p;
//     newrec = (node *)malloc(sizeof(node));
//     newrec->data = ele;
//     newrec->next = NULL;

//     if (l->start == NULL)
//         l->start = newrec;
//     else
//     {
//         p = l->start;
//         while (p->next != NULL)
//             p = p->next;
//         p->next = newrec;
//     }
// }

// int count(LL *l)
// {
//     node *p;
//     int c = 0;
//     p = l->start;
//     while (p != NULL)
//     {
//         c++;
//         p = p->next;
//     }

//     return c;
// }

// void insertAt(LL *l, int ele, int pos)
// {
//     node *newrec, *p;
//     int i;

//     newrec = (node *)malloc(sizeof(node));
//     newrec->data = ele;
//     if (pos > count(l) + 1)
//     {
//         printf("Invalid choice\n");
//         return;
//     }

//     if (pos == 1)
//     {
//         newrec->next = l->start;
//         l->start = newrec;
//         return;
//     }
//     p = l->start;
//     for (i = 1; i < pos - 1; i++)
//     {
//         p = p->next;
//     }
//     newrec->next = p->next;
//     p->next = newrec;
// }

// void display(LL *l)
// {
//     node *p;
//     if (l->start == NULL)
//     {
//         printf("Linked list is empty\n");
//         return;
//     }
//     else
//     {
//         p = l->start;
//         while (p != NULL)
//         {
//             printf("%d ", p->data);
//             p = p->next;
//         }
//         printf("\n");
//     }
// }
// int deletebegining(LL *l)
// {
//     node *p;
//     if (l->start == NULL)
//         return -1;
//     p = l->start;
//     l->start = p->next;
//     p->next = NULL;
//     return p->data;
// }

// int deleteend(LL *l)
// {
//     node *p, *q;
//     if (l->start == NULL)
//         return -1;
//     if (l->start->next == NULL)
//     {
//         p = l->start;
//         l->start = NULL;
//         return p->data;
//     }
//     else
//     {
//         while (q->next->next != NULL)
//             q = q->next;
//         p = q->next;
//         q->next = NULL;
//         return p->data;
//     }
// }

// int deleteat(LL *l, int pos)
// {
//     node *p, *q;
//     int i;

//     if (pos == 1)
//     {
//         p = l->start;
//         l->start = p->next;
//         p->next = NULL;
//         return p->data;
//     }
//     q = l->start;
//     for (i = 1; i < pos - 1; i++)
//         q = q->next;

//     p = q->next;       //
//     q->next = p->next; // check these lines
//     p->next = NULL;    //
//     return p->data;
// }

// void deleteelement(LL *l, int ele)
// {
//     node *p, *q;
//     if (l->start == NULL)
//     {
//         printf("LL is empty\n");
//         return;
//     }
//     if (l->start->data == ele)
//     {
//         p = l->start;
//         l->start = p->next;
//         p->next = NULL;
//         return;
//     }
//     q = l->start;
//     while (q->next != NULL)
//     {
//         if (ele == q->next->data)
//             break;
//         q = q->next;
//     }
//     p = q->next;

//     if (p == NULL)
//         printf("Element is not present\n");
//     else
//     {
//         q->data = p->next;
//         q->next - NULL;
//     }
// }
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
void InsertBegin(LL *l, int ele)
{
    node *newrec;
    newrec = (node *)malloc(sizeof(node));
    newrec->data = ele;
    newrec->next = l->start;
    l->start = newrec;
}
void InsertEnd(LL *l, int ele)
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
void InsertAtPosition(LL *l, int ele, int pos)
{
    int i;
    node *newrec, *p;
    newrec = (node *)malloc(sizeof(node));
    newrec->data = ele;
    newrec->next = NULL;

    if (pos > count(l) + 1)
    {
        printf("\nInvalid Position...");
    }
    else if (pos == 1)
    {
        newrec->next = l->start;
        l->start = newrec;
    }
    else
    {
        p = l->start;
        for (i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        newrec->next = p->next;
        p->next = newrec;
    }
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
int count(LL *l)
{
    node *p;
    int count = 0;
    p = l->start;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int DeleteBegin(LL *l)
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
int DeleteEnd(LL *l)
{
    node *p, *q;
    if (l->start == NULL)
    {
        return -1;
    }
    if (l->start->next == NULL)
    {
        p = l->start;
        l->start = NULL;
    }
    else
    {
        q = l->start;
        while (q->next->next != NULL)
        {
            q = q->next;
        }
        p = q->next;
        q->next = NULL;
        return p->data;
    }
}
int DeleteAtPosition(LL *l, int pos)
{
    int i;
    node *p, *q;
    if (pos == 1)
    {
        p = l->start;
        l->start = l->start->next;
        l->start->next = NULL;
        return p->data;
    }
    q = l->start;
    for (i = 1; i <= pos - 2; i++)
    {
        q = q->next;
    }
    p = q->next;
    q->next = p->next;
    p->next = NULL;
    return p->data;
}

int search(LL *l, int ele)
{
    node *p;
    p = l->start;
    while (p != NULL)
    {

        if (p->data == ele)
        {
            return 1;
        }
        else
        {
            p = p->next;
        }
    }
    return 0;
}
void Sort(LL *l)
{
    int temp;
    node *i, *j;
    for (i = l->start; i->next != NULL; i = i->next)
    {
        for (j = l->start; j->next != NULL; j = j->next)
        {
            if (j->data > j->next->data)
            {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}
void Reverse(LL *l)
{
    node *p, *q, *r;
    p = l->start;
    q = NULL;
    while (p != NULL)
    {
        /* code */
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    l->start = q;
}
int main()
{
    LL l;
    l.start = NULL;
    int ch, ele, pos, x;
    while (1)
    {
        printf("\n\nMenu\n1. InsertBegin\n2. InsertEnd\n3. InsertAtPosition\n4. DeleteBegin\n5. DeleteEnd\n6. DeleteAtPosition\n7. Search\n8. Count No. of Nodes\n9. Display all Nodes\n10. Sort\n11. Reverse\n12. Exit\n");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        if (ch == 12)
        {
            printf("\nExit Satisfied.");
            break;
        }
        switch (ch)
        {
        case 1:
        {
            printf("\nEnter the element to be Inserted at Begining:");
            scanf("%d", &ele);
            InsertBegin(&l, ele);
            display(&l);
        }
        break;
        case 2:
        {
            printf("\nEnter the element to be inserted at end:");
            scanf("%d", &ele);
            InsertEnd(&l, ele);
            display(&l);
        }
        break;
        case 3:
        {
            printf("\nEnter the element to be inserted:");
            scanf("%d", &ele);
            printf("\nEnter the position:");
            scanf("%d", &pos);
            InsertAtPosition(&l, ele, pos);
            display(&l);
        }
        break;
        case 4:
        {
            ele = DeleteBegin(&l);
            display(&l);
        }
        break;
        case 5:
        {
            ele = DeleteEnd(&l);
            display(&l);
        }
        break;
        case 6:
        {
            printf("\nEnter the position:");
            scanf("%d", &pos);
            ele = DeleteAtPosition(&l, pos);
            display(&l);
        }
        break;
        case 7:
        {
            printf("\nEnter the element to be search:");
            scanf("%d", &x);
            ele = search(&l, ele);
            if (ele == 1)
            {
                printf("\nElement is present.");
            }
            else
            {
                printf("\nElement is not present.");
            }
        }
        break;
        case 8:
        {
            ele = count(&l);
            printf("\n nodes present are %d", ele);
        }
        break;
        case 9:
        {
            display(&l);
        }
        break;
        case 10:
        {
            Sort(&l);
            display(&l);
        }
        break;
        case 11:
        {
            Reverse(&l);
            display(&l);
        }
        break;
        default:
        {
            printf("invalid\n");
        }
        }
    }
    return 0;
}
