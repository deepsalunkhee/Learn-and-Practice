#include<stdio.h>
#include<math.h>
int main()
{
	int n,d,c1,c2,s=0,c=0;
	printf("Enter number:\n");
	scanf("%d",&n);
	c2=c1=n;
	while(c1!=0)
	{
		c1=c1/10;
		c++;
	}
	while(c2!=0)
	{
		d=c2%10;
		s=s+pow(d,c);
		c2=c2/10;
	}
	if(n==s)
	{
		printf("Armstrong number");
	}
	else
	{
		printf("Not armstrong number");
	}
	return 0;
}
	
	
	
	
	
