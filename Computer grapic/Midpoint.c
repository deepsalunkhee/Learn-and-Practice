// Midpoint Circle Generation Algorithm
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
main()
{
    int gd, gm;
    int i, r, x, y, xc, yc;
    float p;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter center of circle=");
    scanf("%d %d", &xc, &yc);
    printf("enter radius of circle=");
    scanf("%d", &r);
    x = 0;
    y = r;
    p = 1.25 - r;
    do
    {
        if (p < 0.0)
        {
            x += 1;
            p += (2 * x) + 3;
        }
        else
        {
            x += 1;
            y -= 1;
            p += 2 * (x - y) + 5;
        }
        putpixel(xc + x, yc + y, 15);
        putpixel(xc + x, yc - y, 15);
        putpixel(xc - x, yc + y, 15);
        putpixel(xc - x, yc - y, 15);
        putpixel(xc + y, yc + x, 15);
        putpixel(xc + y, yc - x, 15);
        putpixel(xc - y, yc + x, 15);
        putpixel(xc - y, yc - x, 15);
        delay(50);
    } while (x < y);
    getch();
}