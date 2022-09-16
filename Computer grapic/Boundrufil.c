#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void polygon()
{
    int n, i, j, k;
    int a[20][2];
    printf("enter no of sides in the polyon\n");
    scanf("%d", &n);
    printf("enter the cordinates of each vertex\n");

    for (i = 0; i < n; i++)
    {
        printf("enter the vertex %d", i);
        scanf("%d", &a[i][0]);
        scanf("%d", &a[i][1]);
    }
    printf("ent er the color code\n");
    scanf("%d", &k);

    for (j = 0; j < n; j++)
    {
        setcolor(k);
        line(a[j][0], a[j][1], a[(j + 1) % n][0], a[(j + 1) % n][1]);
        delay(100);
    }
}

void b_fill(int x, int y)
{

    if ((getpixel(x, y) != WHITE) && (getpixel(x, y) != YELLOW))
    {
        putpixel(x, y, YELLOW);
        delay(10);
        b_fill(x, y - 1);
        b_fill(x, y + 1);
        b_fill(x - 1, y);
        b_fill(x + 1, y);
    }
}
main()
{
    int gm, gd, x, y, c;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    polygon();
    printf("Enter seed\n");
    scanf("%d%d", &x, &y);

    printf("enter the color to fill\n");
    scanf("%d", &c);
    b_fill(x, y);

    getch();
    return 0;
}