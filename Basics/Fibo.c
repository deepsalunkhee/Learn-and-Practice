#include<stdio.h>
int main()
{
int n,i,f=1,s=1,t;
printf("enter nos of terms\n");
scanf("%d",&n);
printf("first %d terms of fibo series are\n",n);
if(n==1)
printf("%d\n",f);
else if(n>=2)
{
printf("%d\t%d\t",f,s);
for(i=1;i<=n-2;i++)
{
t=f+s;
printf("%d\t",t);
f=s;
s=t;
}
printf("\n");
}
else
printf("invalid no of terms\n");
return 0;
}