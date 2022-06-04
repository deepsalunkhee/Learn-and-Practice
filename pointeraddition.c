#include <stdio.h>

int main()
{
    int firstno, secondno, *p, *q, sum;
    
    printf("Enter two integers to add\n");
    scanf("%d%d", &firstno, &secondno);
    
    p = &firstno;
    q = &secondno;
    
    sum = *p + *q;
    
    printf("Sum of entered numbers = %d\n",sum);
    
    return 0;
}