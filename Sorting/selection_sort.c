#include <stdio.h>

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int length = sizeof(arr) / sizeof(arr[0]);

    int min = 0;
    for (int i = 0; i < length; i++)
    {
        min = i;
        for (int j = i; j < length; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}