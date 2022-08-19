#include <stdio.h>

#include <string.h>
#define MAX 50

typedef struct
{
    char a[MAX];
    int top;
} stack;


void push(stack *s,char ele)
{
    s->top++;
    s->a[s->top]=ele;
}


int pop(stack *s)
{
    char x;
    x=s->a[s->top];
    s->top--;
    return x;
}

int isempty(stack *s)
{
    if(s->top==-1)
    return 1; 
    else
    return 0;
}
void display(stack *s)
{
    char i;
    if (isempty(s))
    {
        printf("Stack under flow\n");
    }
    else
    {
        for (i = s->top; i >= 0; i--)
        {
            printf("|_%c_|\n", s->a[i]);
        }
    }
}

int importance(char ch)
{
    switch(ch)
    {
        case '(':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '%':
        case '/':return 2;
        default :return -1;
    }
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
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%')
    return 1;
     else
    return 0;
}

void converter(char infix[],char postfix[])
{
    stack s;
    s.top=-1;
    int i,j,k=0,ele;

    for(i=0;i<strlen(infix);i++)
    {
        if(isoperand(infix[i]))
        {
            postfix[k++]=infix[i];
        }
        else if(isoperator(infix[i]))
        {
           push(&s,infix[i]);

        }
       

    
        

    }
    display(&s);

    while(isempty(&s)==0)
    {
        ele=pop(&s);
        postfix[k++]=ele;

    }

    for(j=0;j<k;j++)
    {
        printf("%c ",postfix[j]);
    }
}


    int main()
{
    char infix[50];
    char postfix[50];
    printf("enter the infix expression\n");
    gets(infix);
    
    converter(infix, postfix);
   
    return 0;
}
