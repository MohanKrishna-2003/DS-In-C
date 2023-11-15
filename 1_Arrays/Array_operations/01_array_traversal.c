#include <stdio.h>
void display(int arr[], int n) // 1----> Array Traversal
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    int arr[100] = {7, 18, 12, 27, 88};
    int size = 5;
    display(arr, size);

    return 0;
}