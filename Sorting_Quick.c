#include <stdio.h>
#include <string.h>
#include <math.h>
// Quick Sort

int Partion(int a[], int lb, int ub)
{
    int pivot, start, end;
    pivot = a[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    int temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}
void QuickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = Partion(a, lb, ub);
        QuickSort(a, lb, loc - 1);
        QuickSort(a, loc + 1, ub);
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
    QuickSort(a, 0, n - 1);
    printf("\nArray After sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}