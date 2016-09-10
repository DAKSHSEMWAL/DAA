#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
void swap(int *xp,int *yp,int *f)
{ 
   int temp = *xp;
    *xp = *yp;
    *yp = temp;
   *f++;
}
int main()
{
long int a[10000],n,i,j,min,c=0,t=0;
clock_t t1,t2;
printf("Enter the no of elements ");
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
for(i=0;i<n-2;i++)
{
  min=i;
   for(j=i+1;j<n-1;j++)
   {
   if(a[j]<a[min]&&c++)
   min=j;
   swap(&a[i],&a[min],&c);
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

