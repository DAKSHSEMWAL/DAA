//PROGRAM TO FIND IMPLEMENT TRAPAZOIDAl RULE 
//NAME: Daksh Semwal
//SEC: A|ROLL NO: -38
//COURSE: B. Tech   BRANCH:CS
#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(int x)
{
      return 1/(1+(x*x));
      }
int main()
{
    float n,high,low,h,l=0,i,sum=0;
    printf("Enter the no of sub interval:");
    scanf("%f",&n);
    printf("\nEnter the low interval:");
    scanf("%f",&low);
    printf("\nEnter the high interval:");
    scanf("%f",&high);
    h=(high-low)/n;
    sum=f(high)+f(low);
     for(i=1;i<n;i++)
          {  l=l+f(low+(i*h));
}
             l=2*l;
        sum=(sum+l)*h/2;
        printf("sum is%f",sum);               
     getch();
 return 0;
}    




