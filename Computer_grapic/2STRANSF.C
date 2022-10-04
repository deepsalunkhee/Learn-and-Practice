#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int polygon()
{
	int n,i,j,k;
	int a[20][2];
	
	printf("enter no of sides in the polyon\n");
	scanf("%d",&n);
	printf("enter the cordinates of each vertex\n");
	
	for(i=0;i<n;i++)
	{
		printf("enter the vertex %d",i+1);
		scanf("%d",&a[i][0]);
		scanf("%d",&a[i][1]);
		
	}
	printf("ent er the color code\n");
	scanf("%d",&k);
	
	printf("The original polygon is");
	
	for(j=0;j<n;j++)
	{
		setcolor(k);
		line(a[j][0],a[j][1],a[(j+1)%n][0],a[(j+1)%n][1]);
		delay(100);
	}
	
	
	
	
	getch();
	
	return 0;
}

int translation()
{
	int n,i,j,k,TFx,TFy;
	int a[20][2];
	
	printf("enter no of sides in the polyon\n");
	scanf("%d",&n);
	printf("enter the cordinates of each vertex\n");
	
	for(i=0;i<n;i++)
	{
		printf("enter the vertex %d",i+1);
		scanf("%d",&a[i][0]);
		scanf("%d",&a[i][1]);
		
	}
	printf("ent er the color code\n");
	scanf("%d",&k);
	
	printf("The original polygon is");
	
	for(j=0;j<n;j++)
	{
		setcolor(k);
		line(a[j][0],a[j][1],a[(j+1)%n][0],a[(j+1)%n][1]);
		delay(100);
	}
	
	
	printf("Enter the transkation factor");
	
	scanf("%d",&TFx);
	scanf("%d",&TFy);
	
	
	printf("The translated  polygon is");
	
	for(j=0;j<n;j++)
	{
		setcolor(k);
		line(a[j][0]+TFx,a[j][1]+TFy,a[(j+1)%n][0]+TFx,a[(j+1)%n][1]+TFy);
		delay(100);
	}
	
	
	
	
	
	
	
	
	
	getch();
	
	return 0;
	
}

int rotation()
{
	
	int n,i,j,k;
	int a[20][2];
	
	printf("enter no of sides in the polyon\n");
	scanf("%d",&n);
	printf("enter the cordinates of each vertex\n");
	
	for(i=0;i<n;i++)
	{
		printf("enter the vertex %d",i+1);
		scanf("%d",&a[i][0]);
		scanf("%d",&a[i][1]);
		
	}
	printf("ent er the color code\n");
	scanf("%d",&k);
	
	printf("The original polygon is");
	
	for(j=0;j<n;j++)
	{
		setcolor(k);
		line(a[j][0],a[j][1],a[(j+1)%n][0],a[(j+1)%n][1]);
		delay(100);
	}
	
	
	
	
	getch();
	
	return 0;
	
}


int scaling()
{
	int n,i,j,k,sx,sy,p1,p2,p3,p4;
	int a[20][2];
	
	printf("enter no of sides in the polyon\n");
	scanf("%d",&n);
	printf("enter the cordinates of each vertex\n");
	
	for(i=0;i<n;i++)
	{
		printf("enter the vertex %d",i+1);
		scanf("%d",&a[i][0]);
		scanf("%d",&a[i][1]);
		
	}
	printf("ent er the color code\n");
	scanf("%d",&k);
	
	printf("The original polygon is");
	
	for(j=0;j<n;j++)
	{
		setcolor(k);
		line(a[j][0],a[j][1],a[(j+1)%n][0],a[(j+1)%n][1]);
		delay(100);
	}
	
	
	printf("Enter the scaling factor");
	scanf("%d",sx);
	scanf("%d",sy);
	printf("ent er the color code\n");
	scanf("%d",&k);
	
		printf("The scaled polygon is");
	
	for(j=0;j<n;j++)
	{
		p1=a[j][0]*sx;
		p2=(a[j][1])*sy;
		p3=(a[(j+1)%n][0])*sx;
		p4=(a[(j+1)%n][1])*sy;

		setcolor(k);
		line(p1,p2,p3,p4);
		delay(100);
	}
	
	
	
	
	
	
	getch();
	
	return 0;
	
}


main()
{
int gm,gd;
int a[20][2];
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
//polygon();
//translation();
//rotation();
scaling();





	getch();
	
	return 0;
	
	

}



