#include <stdio.h>

int arrange(int arr[], int low, int high)
{
    int pivot = high;
    int i = low;
    int j = low;

    for (; j <= high; j++)
    {
        if (arr[j] <= arr[pivot])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    return i - 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i = arrange(arr, low, high);
        quicksort(arr, low, i - 1);
        quicksort(arr, i, high);
    }
}

int main()
{
    int arr[] = {234, 234, 324, 12, 42, 5, 534, 2345};
    int length = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}