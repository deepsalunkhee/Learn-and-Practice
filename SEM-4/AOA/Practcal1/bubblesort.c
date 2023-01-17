#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubblesort(int a[],int size)
{
    int i,j,temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


int main()
{
    int size,i;
    clock_t t;
    scanf("%d",&size);
    int *a;
    FILE *arr;
    FILE *arrsort;
    a=(int *)malloc(sizeof(int)*size);
    arr=fopen("E:\\GIt\\SEM-4\\AOA\\Practcal1\\arr.txt","r");
    for( i=0;i<size;i++)
    fscanf(arr,"%d",&a[i]);
    t = clock();
    bubblesort(a,size);
    t = clock() - t;
    // for( i=0;i<size;i++)
    // printf("%d\t",a[i]);
    arr=fopen("E:\\GIt\\SEM-4\\AOA\\Practcal1\\arrsort.txt","w");
    for( i=0;i<size;i++)
    fprintf(arr,"%d\n",a[i]);
    double timetosort = ((double)t)/CLOCKS_PER_SEC;
    printf("%d",timetosort);
    return 0;
}