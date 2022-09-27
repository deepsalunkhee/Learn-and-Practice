#include<stdio.h>
#include<string.h>
struct info
{
    /* data */
    int No;
    char name[30];
    int marrks;
};
int main()
{    int n;
    printf("Enter no of students:\n");
     scanf("%d",&n);
   
    struct info s[n];
    
   
   
   for(int i=1;i<=n;i++)
   {
    printf("enter the info of the fisr sttudent no:%d\n",i);
    printf("Enter roll no;\n");
    scanf("%d",&s[i].No);

   }

   for (int i = 1; i <=n; i++)
   {
    /* code */
    printf("Student no:%d\n",i);
    printf("rollno:%d\n",s[i].No);
   }
   
   return 0;

}
