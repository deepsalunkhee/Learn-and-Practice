#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubblesort(int a[],int size)
{
    int i,j,temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1;j++)
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
    arr=fopen("E:\\GIt\\SEM-4\\AOA\\Practcal1\\arr.txt","w");


    for( i=0;i<size;i++)
    fprintf(arr,"%d\n",(rand()));

    fclose(arr);

    arr=fopen("E:\\GIt\\SEM-4\\AOA\\Practcal1\\arr.txt","r");
    for( i=0;i<size;i++)
    fscanf(arr,"%d",&a[i]);

    

    clock_t start = clock();
    bubblesort(a,size);
    clock_t end = clock();


    arrsort=fopen("E:\\GIt\\SEM-4\\AOA\\Practcal1\\arrsort.txt","w");
    for( int i=0;i<size;i++)
    fprintf(arrsort,"%d\n",a[i]);


    
    
    
    double timetosort = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("%ld",timetosort);
    return 0;
}