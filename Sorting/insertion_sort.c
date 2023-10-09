#include <stdio.h>

int main()
{
    int arr[] = {43, 213, 4, 13, 432};
    int length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < length; i++)
    {
        int k = i;
        int temp = arr[k];
        while (temp <= arr[k] && k >= 0)
        {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k + 1] = temp;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}