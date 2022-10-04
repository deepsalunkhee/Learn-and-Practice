#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;
    int x = x1;
    int y = y1;
    int i = 0;
    while (i <= dx)
    {
        if (p < 0)
        {
            putpixel(x, y, WHITE);
            x = x + 1;
            p = p + 2 * dy;
        }
        else
        {
            putpixel(x, y, RED);
            x = x + 1;
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        i++;
        delay(50);
    }
}
int main()
{
    int x, y, x1, y1, x2, y2, dx, dy, p, i;
    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("ENTER COORDINATES OF FIRST POINT\n");
    scanf("%d%d", &x1, &y1);
    printf("ENTER COORDINATES OF SECOND POINT\n");
    scanf("%d%d", &x2, &y2);
    Bresenham(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}