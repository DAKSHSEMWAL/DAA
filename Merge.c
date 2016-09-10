#include<conio.h>
#include<time.h>
#include<math.h>
#include<stdio.h>
int c=0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
	{
        L[i] = arr[l + i];
    	c++;
	}
    for (j = 0; j < n2; j++)
    {
    	R[j] = arr[m + 1+ j];
    	c++;
    }
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
        	c++;
            arr[k] = L[i];
            i++;
        }
        else
        {
        	c++;
            arr[k] = R[j];
            j++;
        }
        k++;
        c++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        c++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        c++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
    	c++;
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A [], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A [i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    int arr[100000],i,n;
    clock_t t1,t2;
    printf("\n Enter no of elements :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
       arr[i]=rand()%100;
    printf("Array Before Sorting \n");
    printArray(arr, n);
 	t1=clock();
    mergeSort(arr, 0, n-1);
 	t2=clock();
    printf("\nArray After Sorting\n");
    printArray(arr, n);
    printf("\nTotal no of steps taken%d\n",c);
    printf("\nTotal time taken%d\n",t2-t1);
    return 0;
}
