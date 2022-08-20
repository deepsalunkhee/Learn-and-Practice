// Boundary Fill Algorithm
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

fill_right(int x, int y)
{

    if ((getpixel(x, y) != WHITE) && (getpixel(x, y) != RED))
    {
        putpixel(x, y, RED);
        fill_right(++x, y);
        x = x - 1;
        fill_right(x, y - 1);
        fill_right(x, y + 1);
    }
}
fill_left(int x, int y)

{
    if ((getpixel(x, y) != WHITE) && (getpixel(x, y) != RED))
    {
        putpixel(x, y, RED);
        fill_left(--x, y);
        x = x + 1;
        fill_left(x, y - 1);
        fill_left(x, y + 1);
    }
}
main()
{
    int x, y, a[10][10];
    int gd, gm, n, i, j, k;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("\n\n\tEnter the no. of edges of polygon : ");
    scanf("%d", &n);
    printf("\n\n\tEnter the cordinates of polygon :\n\n\n ");
    scanf("%d", &j, &k);
    for (i = 0; i < n; i++)
    {
        printf("\tX%d Y%d : ", i, i);
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];
    printf("\n\n\tEnter the seed pt. : ");
    scanf("%d%d", &x, &y);
    cleardevice();
    setcolor(WHITE);
    for (i = 0; i < n; i++) /*- draw poly -*/
    {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }
    fill_right(x, y);
    fill_left(x - 1, y);
    getch();
}