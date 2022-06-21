#include<stdio.h>
void read(int a[10][10],int r, int c)
{
int i,j;
for(i=0;i<r;i++)
{
 for(j=0;j<c;j++)
 {
 
 scanf("%d",&a[i][j]);
 }
}
}


void display(int a[10][10],int r, int c)
{
int i,j;
for(i=0;i<r;i++)
{
 for(j=0;j<c;j++)
 {
 printf("%d ",a[i][j]);
 }
 printf("\n");
}
}
void transpose(int a[10][10],int t[10][10],int r,int c)
{int i,j;
for(i=0;i<c;i++)// t will have c no of rows
{
for(j=0;j<r;j++)// t will have r no of cols
t[i][j]=a[j][i];
}
}
int main()
{
int a[10][10],t[10][10],r,c;
 //original a will have r rows and c col
 // transpose t will have c rows and r cols
printf("Enter the number of rows and cols\n");
scanf("%d%d",&r,&c);
printf("enter elements in original matrix\n");
read(a,r,c);
transpose(a,t,r,c);
printf("original matrix is \n");
display(a,r,c);
 

printf("transpose matrix is \n");
display(t,c,r);
return 0;
}
