#include<stdio.h>
int main()
{
	int a[100],n,i,c,j,temp,z;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element:\n");
		scanf("%d",&a[i]);
	}
	do
	{
	printf("\nMenu:\n1-Left Shift\n2-Right Shift\nEnter choice:\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			{
				i=0;
				j=1;
				temp=a[0];
				while(j<n)
				{
					a[i]=a[j];
					i++;
					j++;
				}
				a[n-1]=temp;
				for(i=0;i<n;i++)
				{
					printf("\t%d",a[i]);
				}
			}
			break;
		case 2:
			{
				i=n-1;
				j=n-2;
				temp=a[n-1];
				while(j>=0)
				{
					a[i]=a[j];
					i--;
					j--;
				}
				a[0]=temp;
				for(i=0;i<n;i++)
				{
					printf("\t%d",a[i]);
				}
			}
			break;
		default:
			{
				printf("\nInvalid Choice...");
			}
	}
	printf("\nPress 1 to continue...");
	scanf("%d",&z);
	}while(z==1);
	return 0;
}
