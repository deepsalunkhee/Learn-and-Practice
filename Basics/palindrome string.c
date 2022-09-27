#include<stdio.h>
#include<string.h>
int main()
{ char s1[25];
int i,j,f=1;
printf("enter the string\n");
gets(s1);
i=0;
j=strlen(s1)-1;
while(i<j)
{
if(s1[i]!=s1[j])
{
f=0;
break;
}
i++;
j--;
}
if(f==0)
printf("string %s is not a palindrome\n",s1);
else
printf("string %s is a palindrome\n",s1);
return 0; 
}