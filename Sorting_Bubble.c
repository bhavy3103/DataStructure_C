#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the total number count which you want to sort :  ");
    scanf("%d", &n);
    int a[n], temp, flag = 0;
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
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    printf("\nArray after Sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}