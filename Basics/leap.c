#include<stdio.h>
int main()
{
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    if(n%400==0||(n%4==0 && !(n%100==0)))
    {
        printf("%d is lead year",n);
    }
    else
    {
     printf(" %d is not leap year",n);
    }
    return 0;

}