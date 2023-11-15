#include <stdio.h>
void display(int arr[], int n) // 1----> Array Traversal
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int indIsertion(int arr[], int size, int element, int capacity, int index)   // 2----> Array Insertion
{
    if (size >= capacity)
    {
        printf("Array size exceeded\n");
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
    }
    return 1;
}

int main()
{
    int arr[100] = {7, 18, 12, 27, 88};
    int size = 5;
    int element = 34, capacity = 100, index = 3;
    display(arr, size);
    indIsertion(arr, size, element, capacity, index);
    size += 1;
    display(arr, size);

    return 0;
}