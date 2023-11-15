#include<stdio.h>
void printArray(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// GIVES AN TIME COMPLEXTY OF O(n^2)
void bubbleSort(int *a, int n)  
{
    int temp;
    for(int i=0; i<n-1; i++)  // FOR NUMBER OF PASSES
    {
        for(int j=0; j<n-1-i; j++)  //  FOR COMPARISON IN EACH PASS
        {
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }

    }
}
// GIVES AN TIME COMPLEXITY OF O(n) IF THE ARRAY IS ALREADY SORTED WHICH IS ADAPTIVE
void bubbleSortAdaptive(int *a, int n)
{
    int temp;
    int isSorted = 0;
    for(int i=0; i<n-1; i++)  // FOR NUMBER OF PASSES
    {
        printf("Working on pass number %d\n", i+1);
        isSorted = 1;
        for(int j=0; j<n-1-i; j++)  // FOR COMPARISON IN EACH PASS
        {
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}
int main()
{
    // int a[100];
    // int n;
    // printf("Enter the size of the array:\n");
    // scanf("%d", &n);
    // printf("Enter the elements into an array:\n");
    // for(int i=0; i<n; i++){
    //     scanf("%d ", &a[i]);
    // }
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    printArray(a, n);
    // bubbleSort(a, n);
    bubbleSortAdaptive(a, n);
    printArray(a, n); 
}