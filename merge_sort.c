#include <stdio.h>
#include <stdlib.h>
// Function to merge subarrays by comparing them 
//Arguments of the function are:
//Pointer to array
//lowermost index
//uppermost index
//mid index
void merge(int *A, int l, int m, int h)
{
    int i=l, j=m+1, k=l;
    int *B = (int *)malloc((h+1)*sizeof(int));   // Creating a temporary array to store sorted elements

    while (i<=m && j<=h)
    {
        if (A[i]<A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else                                   //Loop to compare elements of subarrays and merge them to a single array
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i<=m)
    {
        B[k] = A[i];
        k++;
        i++;
    }
                                            //Storing remaining elements of one of the subarrays if the other
    while (j<=h)                            // has been scanned
    {
        B[k] = A[j];
        k++;
        j++; 
    }

    for (int i=l;i<=h;i++)
    {
        A[i] = B[i];
    }

    free(B);
}

//Recursive function for merge sort
void merge_sort(int *A, int l, int h)
{
    if (l<h)
    {
        int m = (l+h)/2;
        merge_sort(A, l, m);           //Calling merge_sort() recursively for left subarray
        merge_sort(A, m+1, h);         //Calling merge_sort() recursively for right subarray
        merge(A, l, m, h);
    }
}
//Function to print the array
void PrintArray(int A[], int l, int h)
{
    for (int i=l;i<=h;i++)
    {
        printf(" %d", A[i]);
    }
    printf("\n");
}

int main(void)
{
    int n;
    int *A = (int *)malloc(n*sizeof(int));     //Creating dynamic array

    printf("Enter number of elements of the array : ");
    scanf("%d", &n);

    for (int i=0;i<n;i++)
    {
        printf("Enter element %d : ", i);
        scanf(" %d", (A+i));
    }

    printf("The orignal array is : ");
    PrintArray(A, 0, n-1);


    merge_sort(A, 0, n-1);
    printf("The sorted array is : ");
    PrintArray(A, 0, n-1);


    free(A);
    return 0;
}