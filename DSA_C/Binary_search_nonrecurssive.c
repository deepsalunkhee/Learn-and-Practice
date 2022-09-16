// binary search

// note:the array should be sorted

#include <stdio.h>

int binart_search_nonrecurssive(int a[], int n, int ele)
{
    int high, low, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (high >= low)
    {
        if (a[mid] == ele)
        {
            return 1;
        }
        else if (ele > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

        mid = (low + high) / 2;
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

    if (binart_search_nonrecurssive(a, n, x))
    {
        printf("element is  present");
    }
    else
    {

        printf("element is not present");
    }

    return 0;
}