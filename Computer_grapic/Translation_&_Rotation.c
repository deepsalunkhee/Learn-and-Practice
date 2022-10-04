// 2D geometric transformation on an object like translation,
// rotation.
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
main()
{
    int gd, gm, m, n, i, a[10][2], b[10][2], tx, ty, sx, sy;
    float t;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    // Accepting vertices and its coordinates
    printf("Accept the no of vertices of polygon - ");

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Accept end pt coordinates of vertices");
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    // to close polygon
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];
    line(320, 0, 320, 480);
    line(0, 240, 640, 240);
    for (i = 0; i < n; i++)
    {
        line(320 + a[i][0], 240 + a[i][1], 320 + a[i + 1][0], 240 + a[i + 1][1]);
    }
    printf("Enter your Choice\n1.Translation\n2.Rotation\n");
    scanf("%d", &m);
    switch (m)
    {
    case 1:
        printf("Enter translation parameters:");

        scanf("%d %d", &tx, &ty);
        for (i = 0; i < n; i++)
        {
            b[i][0] = a[i][0] + tx; // x'=x+tx
            b[i][1] = a[i][1] + ty; // y'=y+ty
        }
        // to close new poly
        b[n][0] = b[0][0];
        b[n][1] = b[0][1];
        // display new poly
        for (i = 0; i < n; i++)
        {
            line(320 + b[i][0], 240 + b[i][1], 320 + b[i + 1][0], 240 + b[i + 1][1]);
        }
        break;
    // 2D Rotation
    case 2:
        printf("Enter angle of rotation");
        scanf("%f", &t);
        t = (t * 3.142) / 180;
        for (i = 0; i < n; i++)
        {

            b[i][0] = (a[i][0] * cos(t) - a[i][1] * sin(t)); // x'=x.cos(t)-y.sin(t)
            b[i][1] = (a[i][0] * sin(t) + a[i][1] * cos(t)); // y'=x.sin(t)+y.cos(t)
        }
        b[n][0] = b[0][0];
        b[n][1] = b[0][1];
        // Display new poly
        for (i = 0; i < n; i++)
        {
            line(320 + b[i][0], 240 + b[i][1], 320 + b[i + 1][0], 240 + b[i + 1][1]);
        }
        break;
    default:
        printf("INVALID CHOICE");
    }
    getch();
}
