#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int round(float j)
{ int k=j;
    if((j-k)>0.5)
    return ceil(j);
    else
    return floor(j);
}
void DDA(int x1,int y1,int x2, int y2)
{
    float xi,yi,dx,dy,x,y;
    int i,step;

    dx=x1-x2;
    dy=y1-y2;
      
    if(abs(dx)>abs(dy))
    {
        step=abs(dx);
        
    }
    else
     {
        step=abs(dy);
        
    }


    xi=dx/step;
    yi=dy/step;

    for( i=0; i<=step; i++)
    {
        putpixel(round(x),round(y),RED);
        x=x+xi;
        y=y+yi;
    }



}


int main()
{

    int  gd = DETECT, gm,a,b,c,d;;
 
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

   
    printf("Enter end pint and the starting points:\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    DDA(a,b,c,d);
    line(a,c,b,d);
     getch();
    return 0;
}