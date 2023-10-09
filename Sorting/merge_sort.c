#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int left_length = mid - low + 1;
    int right_length = high - mid;

    int left[left_length], right[right_length];

    for (int i = 0; i < left_length; i++)
    {
        left[i] = arr[low + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;

    int k = low;

    while (i < left_length && j < right_length)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_length)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_length)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int length = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}