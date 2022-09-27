#include<stdio.h>
void read(int a[10][10],int r,int c )
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
           scanf("%d",&a[i][j]);
        }
        
    }
    
}


void display(int a[10][10],int r,int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
          printf("%d",a[i][j]);
        }
        printf("\n");
        
    }
    
}

void kshitij(int a[10][10],int r,int c,int t[10][10])
{
     for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
         t[i][j]=a[j][i];
        }
        printf("\n");
        
    }
}


int main()
{
    int r,c;
    int a[10][10];
    int t[10][10];
    printf("enter rows in matric:\n");
    scanf("%d",&r);
    printf("enter cloumns in matric:\n");
    scanf("%d",&c);
    printf("enter   matric:\n");

    read(a,r,c);
     
     printf("the original matric is:\n");
     display(a,r,c);

     printf("The transpose is:\n");

    kshitij(a,r,c,t);
    display(t,c,r);

     return 0;



}