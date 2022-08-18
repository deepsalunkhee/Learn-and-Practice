#include <stdio.h>
int main()
{
    int x;
    int *y;
    x = 10;
    y = &x;
    scanf("%d", y);

    printf("%d\n", y);
    printf("%d\n", x);
    printf("%d", *y);
    return 0;
}