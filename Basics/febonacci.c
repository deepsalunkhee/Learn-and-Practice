#include<stdio.h>
int main()
{
    int n,f=0,s=1,t;
    printf("enter no of terms in the series:\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("%d\t",f);
    }
    else if(n>=2)
    {
    printf("%d\t%d\t",f,s);
    for(int i=1;i<=n-2;i++)
    {
        
        t=f+s;
        printf("%d\t",t);
        f=s;
        s=t;
    }
    printf("\n");
    }
    else
    {
        printf("Invalid term");
    }
    return 0;
}