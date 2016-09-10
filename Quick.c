#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
int c=0;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
    c++;
}
 int partition (long int arr[], int l, int h)
{
    int x = arr[h];    
    int i = (l - 1);   
    int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
        	c++;
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}
void quickSort(long int arr[],int l, int h)
{
    if (l < h)
    {
    	c++;
        int p = partition(arr, l, h); 
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
        c++;
    }
}
 
void printArray(long int arr[],long int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%ld ", arr[i]);
    printf("\n");
}
int main()
{
    long int arr[10000],n,i,j;
    clock_t t1,t2;
	printf("Enter the no of elements ");
	scanf("%d",&n);
    for(i=0;i<n;i++)
	{
	   arr[i]=rand()%100;
	}
    printf("Array Before Sorting: \n");
    printArray(arr, n);
    t1=clock();
    quickSort(arr, 0, n-1);
    t2=clock();
	printf("Array After Sorting\n");
    printArray(arr, n);
    printf("\nNo of Steps %d ",c);
	printf("\nTime Taken %d ",t2-t1);	
    return 0;
}
