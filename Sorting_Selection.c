#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the total number count which you want to sort :  ");
    scanf("%d", &n);
    int a[n], min, temp;
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
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    printf("\nArray after sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}