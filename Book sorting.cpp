#include<stdio.h>
struct book
{
	int price;
    char title[50];
    char author[50];
};
int main()
{   
    int i,j;
	struct book bk[5],temp;
	for(i=0;i<5;i++)
	{
		printf("Enter details for Book %d\n",i+1);
		printf("Enter name\n");
		scanf("%s",&bk[i].title);
		printf("Enter author\n");
		scanf("%s",&bk[i].title);
		printf("Enter price\n");
		scanf("%d",bk[i].price);
    }
	for(i=0;i<5;i++)
    {
printf(" Title : %s\n",bk[i].title);
printf(" Author Name : %s\n",bk[i].author);
printf(" Price : %d\n",bk[i].price);
    }
return 0;
}