// Flood Filling Algorithm
#include <stdio.h>
#include <graphics.h>
flood_fill(int x, int y, int new_col, int old_col)
{
    if (getpixel(x, y) == old_col)
    {
        putpixel(x, y, new_col);
        flood_fill(x + 1, y, new_col, old_col);
        flood_fill(x - 1, y, new_col, old_col);
        flood_fill(x, y + 1, new_col, old_col);
        flood_fill(x, y - 1, new_col, old_col);
    }
}

void poly()
{
    int n, x[10], y[10], k = 0, ymin = 1000000, ymax = 0, Y, dx, dy, xi[100], gm, gd, temp, i, m, j;

    float slope[100];

    printf("Enter the number of vertices:");

    scanf("%d", &n);

    printf("enter the coordinates of vertices:");

    for (i = 0; i < n; i++)

    {

        scanf("%d%d", &x[i], &y[i]);

        if (y[i] > ymax)

            ymax = y[i];

        if (y[i] < ymin)

            ymin = y[i];
    }
    x[n] = x[0];
    y[n] = y[0];

    // draw polygon using all the edges

    for (i = 0; i < n; i++)

    {

        line(x[i], y[i], x[i + 1], y[i + 1]);
    }

    return 0;
}
main()
{
    int gd, gm, c1, c2;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    // circle(200, 150, 35);
    // circle(100, 150, 35);
    // arc(150, 150, 45, 135, 35);
    // arc(150, 150, 225, 315, 35);
    // arc(150, 115, 0, 180, 50);
    // arc(150, 185, 180, 360, 50);
    // flood_fill(200, 150, GREEN, getpixel(200, 150));
    // flood_fill(150, 150, YELLOW, getpixel(150, 150));
    // flood_fill(80, 150, BROWN, getpixel(80, 150));
    // flood_fill(150, 100, RED, getpixel(150, 100));
    // flood_fill(150, 200, BLUE, getpixel(150, 200));
    poly();
    printf("enter the seed coordinates\n");
    scanf("%d", &c1);
    scanf("%d", &c2);
    flood_fill(c1, c2, RED, getpixel(c1, c2));

    getch();
    closegraph();
}