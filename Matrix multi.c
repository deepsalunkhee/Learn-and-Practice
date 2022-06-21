#include<stdio.h>
void read(int a[10][10], int r, int c)
{
int i,j;
for(i=0;i<r;i++)
 for (j=0; j<c; j++)
 scanf("%d",&a[i][j]);
}
void display(int a[10][10], int r, int c)
{
int i,j;
for(i=0;i<r;i++)
{
 for (j=0; j<c; j++)
 printf("%d ",a[i][j]);
 printf("\n");
}
}
void multiply(int a[10][10],int b[10][10],int c[10][10],int 
 r1,int c1,int r2,int c2)
{
int i,j,k;
for(i=0;i<r1;i++)
 for (j=0;j<c2;j++)
 {
 c[i][j]=0;
 
 for (k=0;k<c1;k++)
c[i][j]=c[i][j]+a[i][k]*b[k][j];
 
}
}
int main()
{
int a[10][10],b[10][10],c[10][10],r1,c1,r2,c2;

 
printf("Enter order of matrix1\n");
scanf("%d %d",&r1,&c1);
printf("Enter order of matrix2\n");
scanf("%d %d",&r2,&c2);
if(c1==r2)
{
 
 printf("enter elements in first matrix\n");
 read(a,r1,c1);
 printf("enter elements in second matrix\n");
 read(b,r2,c2);
 
 multiply(a,b,c,r1,c1,r2,c2);
 
 printf("elements of first matrix\n");
 display(a,r1,c1);
 
 printf("elements of second matrix\n");
 display(b,r2,c2);
 
 printf("elements of resultant matrix\n");
 display(c,r1,c2);
}
else 
printf("Multiplication not possible\n");
return 0;
}
