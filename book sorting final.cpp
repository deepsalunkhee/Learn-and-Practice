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
for (i=0;i<5;i++)
{
printf(" Enter Book Details \n");
printf(" Enter Title :\n");
scanf("%s",&bk[i].title);
printf(" Enter Author Name :\n");
scanf("%s",&bk[i].author);
printf(" Enter Price :\n");
scanf("%d",&bk[i].price);
}
for(i=0;i<5;i++)
{
printf(" Title : %s\n",bk[i].title);
printf(" Author Name : %s\n",bk[i].author);
printf(" Price : %d\n",bk[i].price);
}
for (i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if (bk[j].price>bk[j+1].price)
{
temp=bk[j];
bk[j]=bk[j+1];
bk[j+1]=temp;
}
}

printf("%d",i);
}
printf(" Book Records :\n");
for(i=0;i<5;i++)
{
printf(" Title : %s\n",bk[i].title);
printf(" Author Name : %s\n",bk[i].author);
printf(" Price : %d\n",bk[i].price);
}
return 0;
}