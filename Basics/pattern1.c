#include<stdio.h>
int main()
{
	int n,i,j,a,s;
	printf("Enter number of lines:\n");
	scanf("%d",&n);
	s=n-1;
	for(i=1;i<=n;i++)
	{
		a=i;
		for(j=1;j<=s;j++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			printf("%d",a);
		}
		printf("\n");
		s--;
	}
	return 0;
}
