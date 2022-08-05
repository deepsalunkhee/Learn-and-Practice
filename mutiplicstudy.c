#include<stdio.h>
void dipakwach(int a[10][10],int r, int c)
{
    for (int i = 0; i < r; i++)
    {
       for (int j = 0; j < c; j++)
       {
        
        
        
        scanf("%d",&a[i][j]);
       }
       
    }
    
}

void dipakdakhiv(int a[10][10],int r, int c)
{
    for (int i = 0; i < r; i++)
    {
       for (int j = 0; j< c; j++)
       {
        printf(" %d ",a[i][j]);
       }

       printf("\n");
       
    }
}

void dipakmulti(int a[10][10],int b[10][10],int c[10][10],int ra, int ca,int rb,int cb)
{
    int j;
    for (int i = 0; i < ra; i++)
    {
        
        for ( j = 0; j < cb; j++)
        {
            c[i][j]=0;
          for (int k = 0; k < ca; k++)
          {
           c[i][j]=c[i][j]+a[i][k]* b[k][j];
            
          }
           
          
        }
        
    }
    
}

int main()
{
    int ra,ca,rb,cb;
   int a[10][10];
   int b[10][10];
   int c[10][10];
    printf("enter no of r and c in m1 and m2\n");
    scanf("%d%d%d%d", &ra,&ca,&rb,&cb);
    printf("enter m1 \n");
    dipakwach(a,ra,ca);
     printf("enter mm2 \n");
     dipakwach(b,rb,cb);
     printf("multiplication is:\n");
     dipakmulti(a,b,c,ra,ca,rb,cb);
     dipakdakhiv(c,ra,cb);


     return 0;


    

}