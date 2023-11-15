#include <stdio.h>
int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            printf("The element %d found at location %d\n", element, mid);
            break;
        }
        else if (element > arr[mid])
        {
            low = mid + 1;
        }
        else if (element < arr[mid])
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {7, 12, 45, 67, 89, 94, 105};
    int size = sizeof(arr) / sizeof(int);
    int element = 67;
    binarySearch(arr, size, element);

    return 0;
}