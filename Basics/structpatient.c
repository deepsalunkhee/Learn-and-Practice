#include<stdio.h>
#include<string.h>
struct patient
{
	int id,amount;
	char name[20];
};
int main()
{
	struct patient p[100],temp;
	int n,i,j;
	printf("Enter number of patients:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter ID,name and bill amount:\n");
		scanf("%d%s%d",&p[i].id,&p[i].name,&p[i].amount);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(strcmp(p[j].name,p[j+1].name)>0)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	printf("\nSorted List=\n");
	for(i=0;i<n;i++)
	{
		
		printf("\n");
		printf("\nID=%d",p[i].id);
		printf("\nName=%s",p[i].name);
		printf("\nBill Amount=%d",p[i].amount);
	}
	return 0;
}
