#include<stdio.h>
int GCD(int m,int n)
{
	if(n>m)
	{
		return GCD(n,m);
	}
	else if(n==0)
	{
		return m;
	}
	else
	{
		return GCD(n,m%n);
	}
}
int main()
{
	int a,b,g;
	printf("Enter 2 numbers=");
	scanf("%d%d",&a,&b);
	g=GCD(a,b);
	printf("\nGCD=%d",g);
	return 0;
}
