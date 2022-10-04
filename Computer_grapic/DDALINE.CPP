#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
int main()
{
int gd,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
int x1,x2,y1,y2,dx,dy,xinc,yinc,steps,x,y;
printf("enter the x1 and y1 and x2 and y2:");
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
int ch=0;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>=abs(dy))
{
 steps=abs(dx);
}else{
ch=1;
steps=abs(dy);
}
xinc=dx/steps;
yinc=dy/steps;
if(yinc==0)
{
ch=1;
}else{
ch=0;
}
x=x1;
y=y1;
int t;
printf("\nenter the thickness:");
scanf("%d",&t);
for(int i=0;i<steps;i++)
{
   delay(10);
   putpixel(x,y,RED);
   if(ch==0)
   {for(int j=1;j<=t;j++)
   {
   putpixel(x+j,y,RED);
   putpixel(x-j,y,RED);
   }
   }else{
   for(int j=1;j<=t;j++)
   {
   putpixel(x,y+j,RED);
   putpixel(x,y-j,RED);
   }
   }
   x+=xinc;
   y+=yinc;
}
getch();
return 0;
}
