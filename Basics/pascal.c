#include<stdio.h>
int fact(int n)
{
	int i,f=1;
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	return f;
}
int main()
{
	int n,i,j,s,a;
	printf("Enter number of lines:\n");
	scanf("%d",&n);
	s=n-1;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=s;j++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			a=fact(i)/(fact(j)*fact(i-j));
			printf("%d ",a);
		}
		printf("\n");
		s--;
	}
	return 0;
}
