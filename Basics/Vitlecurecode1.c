#include<stdio.h>
int main()
{   char k,h,t,q,i;
    int a,b,c,d,e,per;
    printf("Bhai apna Nam to bata\n");
    scanf("%c%c%c%c%c",&k,&h,&t,&q,&i);
    
    printf("%c%c%c%c%c apne MARKS TO BATAA ....\n",k,h,t,q,i);
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
     
    per=(a+b+c+d+e)/5;
    if(per>90)
    {
        printf("apna %c%c%c%c%c to topper nikla\n",k,h,t,q,i);
    }
    else if(per>75)
    {
        printf("bohot badhiya %c%c%c%c%c\n",k,h,t,q,i);
    }
    else if(per>35)
    {
        printf(" ye bhi thik he  %c%c%c%c%c\n",k,h,t,q,i);
    }
    else
    {
       printf(" %c%c%c%c%c saste nashe band kar\n ",k,h,t,q,i);
    

    } 
       printf("so tero ko  mile %d",per);
     return 0;
}