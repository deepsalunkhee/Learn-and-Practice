//knapsack problem

#include<stdio.h>


int n;//number of objects
int m;//capacity of back
int i,j;

int p[100];//price array
int w[100];
float pw[100];

//int descending order
void bubblesort()
{
	for(i=1;i<=n-1;i++)
    {
	for(j=1;j<=n-1;j++)
	{
	if(pw[j]<pw[j+1])
	{
		int temp=pw[j];
		pw[j]=pw[j+1];
		pw[j+1]=temp;
		
		temp=p[j];
		p[j]=p[j+1];
		p[j+1]=temp;
		
		temp=w[j];
		w[j]=w[j+1];
		w[j+1]=temp;
	}
    }
    }
}

	
void knapsack()
{
  float c=m;//remaining capacity
  float profit=0;
  
  int k;
  for(k=1;k<=n;k++)
  {
    if((c-w[k])>=0)
	{
		c=c-w[k];
		profit=profit+p[k];
		printf("\n obj is added with weight %d and profit %d",w[k],p[k]);		 	
	}else{
		break;
	}  	
  }
  if(k<=n)
  {
	profit+=(pw[k]*c);//c is remaing weight
	printf("\n obj is added with weight %f and profit %f",c,pw[k]);	  	
  }	
  printf("\nprofit:%f",profit);
}	


int main()
{
	
	printf("enter the size of bag:");
	scanf("%d",&m);
	printf("enter the number of objects:");
	scanf("%d",&n);

	
	for(i=1;i<=n;i++)
	{
	  printf("ENTER THE PRICE OF %d object:",i);
	  scanf("%d",&p[i]);
	  printf("ENTER THE weight OF %d object:",i);
	  scanf("%d",&w[i]);
	  int tem=(float)(p[i]/w[i]);
	  pw[i]=tem;//pw ratio of that object	
	}
	
	//sort
	bubblesort();
	
	//knapsacklogic
	knapsack();
	
	return 0;
}