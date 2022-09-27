#include<stdio.h>
struct complex
{
	int x,y;
};

struct complex add(struct complex c1,struct complex c2)
{
	struct complex temp;
	temp.x=c1.x+c2.x;
	temp.y=c1.y+c2.y;
	return temp;
}

int main()
{
	struct complex c1,c2,c3;
	printf("Enter real and imaginary part of complex number 1:\n");
	scanf("%d%d",&c1.x,&c1.y);
	printf("\nEnter real and imaginary part of complex number 2:\n");
	scanf("%d%d",&c2.x,&c2.y);
	c3=add(c1,c2);
	printf("\nAddition=%d+i%d",c3.x,c3.y);
	return 0;
}
