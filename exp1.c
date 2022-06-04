#include<stdio.h>
#include<math.h>
int main()
{
	float p,n,r,s,c;

	printf("Enter the principal amount, No. years and rate of interest:");
	scanf("%f%f%f",&p,&n,&r);

	s=(p*n*r)/100;

	c=p*pow((1+r/100),n)-p;

	printf("Simple interest is %f and Compound interest is %f",s,c);

	return 0;

}