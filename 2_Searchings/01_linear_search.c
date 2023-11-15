#include <stdio.h>
int linerSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("The element %d found at index %d\n", element, i);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 12, 45, 67, 34};
    int size = sizeof(arr) / sizeof(int);
    int element = 445;
    linerSearch(arr, size, element);

    return 0;
}