#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main()
{
  int gd,gm;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  //vertices no.
  int n;
  printf("enter the number of vertices:");
  scanf("%d",&n);
  int i,a[10][10];
  for(i=0;i<n;i++)
  {
  printf("enter the co-ordinate of vertex:");
  scanf("%d %d",&a[i][0],&a[i][1]);
  }
  //now put last empty value=first value;
  a[n][0]=a[0][0];
  a[n][1]=a[0][1];
  //printing lines from vertix to vertix to make polygon
  for(i=0;i<n;i++)
  {
  line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
  }
  int b[10][10];
  float theta;
  printf("enter the value of theta in degree:");
  scanf("%f",&theta);
  //conver theta from degree to radian
  theta=theta*(3.14/180);
  //for x dir shear
  for(i=0;i<n;i++)
  { //x=x+yshx;
    b[i][0]=a[i][0]+(a[i][1]*tan(theta));
    //y=y
    b[i][1]=a[i][1];
  }
  //taking b last =b first
  b[n][0]=b[0][0];
  b[n][1]=b[0][1];
  //printing answer
  for(i=0;i<n;i++)
  {
     line(b[i][0],b[i][1],b[i+1][0],b[i+1][1]);
  }
  getch();
  return 0;
}