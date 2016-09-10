#include<conio.h>
#include<time.h>
#include<math.h>
#include<stdio.h>

void main()
{
     int heap[50000], no, i, j, c,s=0, root, temp;
 	clock_t t1,t2;
    printf("\n Enter no of elements :");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
       heap[i]=rand()%100;
    t1=clock();
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
        	s++;
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])   /* to create MAX heap array */
            {
            	s++;
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
        s++;
    }
 
    printf("Heap array : ");
    for (i = 0; i < no; i++)
        printf("%d\t ", heap[i]);
    for (j = no - 1; j >= 0; j--)
    {
    	s++;
        temp = heap[0];
        heap[0] = heap[j];   /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do 
        {
        	s++;
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;s++;
            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
            {
            	s++;
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
        s++;
    } 
    t2=clock();
    printf("\n The sorted array is : ");
    for (i = 0; i < no; i++)
    printf("\t %d", heap[i]);
    printf("\nNo of Steps %d ",s);
	printf("\nTime Taken %d ",t2-t1);
}
