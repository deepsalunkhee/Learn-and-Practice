#include<stdio.h>
#include<conio.h>
void swap(int *x, int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
}
int main() 
{  
 int x=10, y=20,a,b;   
 swap(&a, &b);  // passing value to function
 printf("The Value of x:%d\n",x);
 printf("The Value of y:%d\n",y);
 getch(); 
 return 0;
}  