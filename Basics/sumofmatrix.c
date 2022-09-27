#include<stdio.h>
int main()
{
	int a[10][10];
	int n,i,j,s1=0,s2=0,s3=0,s4=0;
	printf("Enter degree of array:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)//Row
	{
		for(j=0;j<n;j++)//Column
		{
			printf("\nEnter Number:\n");
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			s1=s1+a[i][j];
		}
	}
	printf("\nSum of all array elements:%d",s1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			s2=s2+a[i][j];
		}
		printf("\nSum of row %d=%d",i,s2);
		s2=0;
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			s3=s3+a[i][j];
		}
		printf("\nSum of column %d=%d",j,s3);
		s3=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				s4=s4+a[i][j];
			}
		}
	}
	printf("\nTrace=%d",s4);
	return 0;
}
