#include<stdio.h>
void accept(int x[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nEnter Number:\n");
			scanf("%d",&x[i][j]);
		}
	}
}

void display(int x[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",x[i][j]);
		}
		printf("\n");
	}
}
void multiply(int a[10][10],int b[10][10],int c[10][10],int m1,int n1,int m2,int n2)
{
	int i,j,k;
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			c[i][j]=0;
			for(k=0;k<n1;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
}
int main()
{
	int a[10][10],b[10][10],c[10][10],m1,n1,m2,n2;
	printf("Enter number of rows and columns of matrix 1:\n");
	scanf("%d%d",&m1,&n1);
	printf("Enter number of rows and columns of matrix 2:\n");
	scanf("%d%d",&m2,&n2);
	if(n1==m2)
	{
		accept(a,m1,n1);
		display(a,m1,n1);
		accept(b,m2,n2);
		display(b,m2,n2);
		multiply(a,b,c,m1,n1,m2,n2);
		printf("\nMultiplication Matrix=\n");
		display(c,m1,n2);	
	}
	else
	{
		printf("\nMultiplication of matrix is not possible");
	}
	return 0;
}
	
