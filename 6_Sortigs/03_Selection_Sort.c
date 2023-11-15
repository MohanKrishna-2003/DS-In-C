#include<stdio.h>
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void selectionSort(int a[], int n)
{
    int indexMin, temp;
    for (int i = 0; i < n; i++)
    {
        indexMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[indexMin]){
                indexMin = j;
            }
        }
        temp = a[indexMin];  // SWAPPING THE ELEMENTS
        a[indexMin] = a[i];
        a[i] = temp;
        
    }
    
}
int main()
{
    // int a[] = {3, 5, 2, 13, 12};
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}