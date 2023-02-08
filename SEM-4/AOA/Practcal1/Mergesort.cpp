#include<stdio.h>

void simplemerge(int a[],int lb,int endoffirst,int ub)
{
		int i=lb;
		int asort[100];
		int k=0,t=0,z;
		int j=endoffirst+1;
		while(i<=endoffirst && j<=ub)
		{
			if(a[i]<a[j])
			{
				asort[k++]=a[i++];
			}
			else
			{
				asort[k++]=a[j++];
			}
		}
		
		while(i<=endoffirst)
		{
			asort[k++]=a[i++];
		}
		while(j<=ub)
		{
			asort[k++]=a[j++];
		}
	
		
		for( z=lb;z<=ub;z++ )
		{
			a[z]=asort[t++];
		}
}
int mergesort(int a[],int lb,int ub)
{
  int mid;
  if(lb==ub)
  {
  	return a[lb];
  }
  else
  {
  	mid=(ub+lb)/2;
  	mergesort(a,lb,mid);
  	mergesort(a,mid+1,ub);
  	simplemerge(a,lb,mid,ub);
  }
}

int main()
{
    int size,i;
    int a[100];
    printf("Enter the size of array :");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
    	printf("Enter element No. %d :",i+1);
    	scanf("%d",&a[i]);
	}
	mergesort(a,0,size-1);
	for(i=0;i<size;i++)
    {
    	printf("%d\t",a[i]);
	}
	
    
    return 0;

}