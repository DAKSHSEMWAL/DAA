#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{
long int a[104876],n,i,j,c=0,t=0;
clock_t t1,t2;
printf("Enter the size of array ");
scanf("%d",&n); 
for(i=0;i<n;i++)
{
   a[i]=rand()%100;
}
printf("\nArray before sorting\n");
for(i=0;i<n;i++)
{
   printf("%d ",a[i]);
}
t1=clock();
for (i = 1 ; i <= n - 1; i++) 
{
    j=i;
 
    while(j>0&&a[j]<a[j-1]) 
	{
	  c++;
      t= a[j];
      a[j]=a[j-1];
      a[j-1]=t;
      j--;
      c++;
    }
    c++;
  }
t2=clock();
printf("\nArray after sorting\n");
for(i=0;i<n;i++)
{
   printf("%d ",a[i]);
}
printf("\nNo of Steps %d ",c);
printf("\nTime Taken %d ",t2-t1);
getch();
return 0;
}

