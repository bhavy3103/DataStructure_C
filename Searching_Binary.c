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
    int low, mid, high, flag, temp;
    low = 0;
    high = n - 1;
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
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (a[mid] < val)
            low = mid + 1;
        else
            high = mid;
    }
    if (a[low] == val || a[high] == val)
        printf("Value is found\n");
    else
        printf("Value is not found\n");

    return 0;
}