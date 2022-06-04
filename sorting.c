#include<stdio.h>
void sort(int x[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)//Pass
	{
		for(j=0;j<n-i;j++)//Compare
		{
			if(x[j]>x[j+1])
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	}
}
int main()
{
	int a[100],n,i;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter Element:\n");
		scanf("%d",&a[i]);
	}
	sort(a,n);
	printf("\nSorted array=\n");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	return 0;
}
