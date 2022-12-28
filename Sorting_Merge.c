#include <stdio.h>
#include <string.h>
#include <math.h>
// Merge Sort

void merge(int a[], int mid, int lb, int ub)
{
    int i, j, k, b[100];
    i = lb;
    j = mid + 1;
    k = lb;

    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= ub)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = lb; i <= ub; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, mid, lb, ub);
    }
}

int main()
{
    int n;
    printf("Enter the total number count which you want to sort :  ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d here : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Array Before sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    mergeSort(a, 0, 6);
    printf("\nArray After sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // printArray(a, n);
    return 0;
}