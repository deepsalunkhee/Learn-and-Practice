#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;float A,S;
    printf("Enter 1st side:");
    scanf("%d",&a);
      printf("Enter 2nd side:");
    scanf("%d",&b);  printf("Enter 3rd side:");
    scanf("%d",&c);
    S=(a+b+c)/2.0;
    A=sqrt(S*(S-a)*(S-b)*(S-c));
    printf("Area is :%f",A);
    return 0;
}

