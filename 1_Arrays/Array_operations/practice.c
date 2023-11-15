#include<stdio.h>
void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// int indInsertion(int arr[], int size, int capacity, int element, int index)
// {
//     if(size>=capacity)
//     {
//         printf("Size has exceeded\n");
//     }
//     else
//     {
//         for(int i=size-1; i>=index; i--)
//         {
//             arr[i+1] = arr[i];
//         }
//         arr[index] = element;
//         return 1;
//     }
// }
void indDeletion(int arr[], int size, int index)
{
    for(int i=index; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}
int main()
{
    int arr[100] = { 23, 45, 6,7,  34,5 ,23,};
    int size = 7, capacity = 100, element = 68, index = 4;
    display(arr, size);
    indDeletion(arr, size, index);
    size -=1 ;
    display(arr, size);

    
}