#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter 3 sides of triangle:\n");
	scanf("%d%d%d",&a,&b,&c);
	if((a+b>c)&&(b+c>a)&&(a+c>b))
	{
		printf("\nTriangle can be drawn");
		if((a==b)&&(b==c)&&(a==c))
		{
			printf("\nIt is Equilateral triangle");
		}
		else if((a!=b)&&(a!=c)&&(b!=c))
		{
			printf("\nIt is Scalene triangle");
		}
		else
		{
			printf("\n It is Isoscales triangle");
		}
	}
	else
	{
		printf("\nTriangle cannot be drawn");
	}
	return 0;
}
