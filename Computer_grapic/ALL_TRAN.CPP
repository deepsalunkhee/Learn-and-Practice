#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
//translation function declaration
void translation(int a[10][10],int b[10][10],int n);
//scaling is same as that of translation instead of x=x+tx
//put x=x*sx
//reflection function
void reflection(int a[10][10],int b[10][10],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
   line(320+a[i][0],240+a[i][1],320+a[i+1][0],240+a[i+1][1]);
 }
 for(i=0;i<n;i++)
 {
  b[i][0]=a[i][0];
  b[i][1]=-a[i][1];
 }
 b[n][0]=b[0][0];
 b[n][1]=b[0][1];
 for(i=0;i<n;i++)
 {
 line(320+b[i][0],240+b[i][1],320+b[i+1][0],240+b[i+1][1]);
 }
}
//rotation matrix
void rotation(int a[10][10],int b[10][10],int n)
{int i;
for(i=0;i<n;i++)
{
 line(320+a[i][0],240+a[i][1],320+a[i+1][0],240+a[i+1][1]);
}
float t;
printf("\n enter the value of theta:");
scanf("%f",&t);
t=t*(180/3.14);
for(i=0;i<n;i++)
{
 b[i][0]=a[i][0]*cos(t)-a[i][1]*sin(t);
 b[i][1]=a[i][0]*sin(t)+a[i][1]*cos(t);
}
 b[n][0]=b[0][0];
 b[n][1]=b[0][1];
 for(i=0;i<n;i++)
 {
 line(320+b[i][0],240+b[i][1],320+b[i+1][0],240+b[i+1][1]);
 }
}
int main(){
clrscr();
int gd, gm;
detectgraph(&gd, &gm);
initgraph(&gd, &gm, "C:\\turboc3\\bgi");
int n,i;
printf("\nenter number of vertices:");
scanf("%d",&n);
int a[10][10],b[10][10];
for(i=0;i<n;i++)
{
 printf("\nenter the co-ordinates of vertices %d:",i+1);
 scanf("%d%d",&a[i][0],&a[i][1]);
}
a[n][0]=a[0][0];
a[n][1]=a[0][1];
/*for(i=0;i<n;i++)
{
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
}*/
//calling translation function
//translation(a,b,n);
//calling reflection function
//reflection(a,b,n);
//calling rotation function
rotation(a,b,n);
getch();
return 0;
 }
 //translation function
void translation(int a[10][10],int b[10][10],int n)
{
int tx,ty,i;
printf("\nenter transformation vectors:");
scanf("%d%d",&tx,&ty);
for(i=0;i<n;i++)
{
 b[i][0]=a[i][0]+tx;
 b[i][1]=a[i][1]+ty;
}
b[n][0]=b[0][0];
b[n][1]=b[0][1];
for(i=0;i<n;i++)
{
line(b[i][0],b[i][1],b[i+1][0],b[i+1][1]);
}
}

