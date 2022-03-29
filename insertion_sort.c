#include <stdio.h>
void insertion_sort(int A[], int n)   //Insertion sort function
{
    int key, j;
    
    for (int i=1;i<n;i++)       //loop for each pass
    {
        key = A[i];
        j = i-1;

        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
void printArray(int A[], int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d ", A[i]);          //function to print array
    }
    printf("\n");
}
int main(void)
{
    int A[] = {12, 54, 65, 7, 23, 9};      //declaring array
    int n = 6;                        //size of array
    printArray(A, n);
    insertion_sort(A, n);
    printArray(A, n);
    return 0;
}