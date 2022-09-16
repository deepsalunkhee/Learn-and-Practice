// Binary searcha recurrsive appoarch
#include <stdio.h>
int binarry_search_recurssive(int a[], int low, int high, int ele)
{
    int mid;
    mid = (high + low) / 2;
    if (high >= low)
    {
        if (a[mid] == ele)
        {
            return 1;
        }
        else if (ele > a[mid])
        {
            return binarry_search_recurssive(a, mid + 1, high, ele);
        }
        else
        {
            return binarry_search_recurssive(a, low, mid - 1, ele);
        }
    }

    return 0;
}

void bubble_sort(int a[], int n)
{
    int i, j, t;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int main()
{
    int a[20];
    int n, i, x;
    printf("enter no of the element in the aray");
    scanf("%d", &n);
    printf("the element in the array");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("enter the element top be searched");
    scanf("%d", &x);

    bubble_sort(a, n);

    if (binarry_search_recurssive(a, 0, n - 1, x))
    {
        printf("element is  present");
    }
    else
    {

        printf("element is not present");
    }

    return 0;
}