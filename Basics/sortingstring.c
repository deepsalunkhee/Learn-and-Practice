#include<stdio.h>
#include<string.h>

int main()
{
	char s1[10][10],temp[10];
	int n,i,j;
	printf("Enter number of names:\n");
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++)
	{
		printf("\nEnter name:\n");
		gets(s1[i]);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(strcmp(s1[j],s1[j+1])>0)
			{
				strcpy(temp,s1[j]);
				strcpy(s1[j],s1[j+1]);
				strcpy(s1[j+1],temp);
			}
		}
	}
	printf("\nSorted List=\n");
	for(i=0;i<n;i++)
	{
		printf("\n%s",s1[i]);
	}
	return 0;
}
	
