// Implimebting stack using array my style


#include<stdio.h>
#define MAX 10

struct stack
{
    int a[MAX];
    int top;
};

void push( struct stack *s, int x )
{
    if( s->top==MAX-1)
    {
        printf("Stack over flow");
    }
    else
    {
        s->top++;
        s->a[s->top]=x;
    }
}

int isempty( struct stack *s)
{
    if(s->top==-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    
}

int stack_top( struct stack *s)
{
    if(isempty(s))
    {
        return -1;
    }
    else
    {
        return s->a[s->top];
    }
}





int main()
{
    struct stack s1;
    int ch,element;
    s1.top=-1;
    do
    {
        printf("1:Push\n2:Pop\n3:Stacktop\n4:Display\n5:Exit\n");

        printf("Enter choice:\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("ENTER ELEMENT TO BE PUSHED:\n");
                   scanf("%d",element);
                   push(&s1,element);
                   break;


            case 3:element=stack_top(&s1);
                   if(element==-1)
                   {
                    printf("Stack underflow");
                   }
                   else
                   {
                    printf("Stack top=%d\n",element);
                   }
                   break;
            
        }

        
    }
    while(ch!=5);


    return 0;
}