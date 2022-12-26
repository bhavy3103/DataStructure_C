#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the total number count :  ");
    scanf("%d", &n);
    int a[n], val, ct = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d here : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter the value here which you want to search : ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            ct++;
        }
    }
    if (ct > 0)
    {
        printf("Value found at position : ");
        for (int i = 0; i < n; i++)
        {
            if (a[i] == val)
                printf("%d ", i + 1);
        }
    }
    else
        printf("Value is not found!!!");

    return 0;
}