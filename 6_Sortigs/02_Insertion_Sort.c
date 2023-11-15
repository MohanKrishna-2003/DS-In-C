#include<stdio.h>
void printArray(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}
void insertionSort(int *a, int n)  // IT IS ADAPTIVE BY DEFAULT
{
    int key, j=0;
    for(int i=1; i<=n-1; i++)  //  LOOP FOR PASSES
    {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key)   // LOOP FOR EACH PASS
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main()
{
    int a[] = {12, 34, 11, 67, 4, 1, 2};
    int n = 7;
    printf("Elements before sorting:\n");
    printArray(a, n);
    printf("\n");
    insertionSort(a, n);
    printf("Elements after sorting:\n");
    printArray(a, n);

}