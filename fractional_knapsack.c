#include<stdio.h>
#include<conio.h>

int next_best_index(float *a,int n)
{
    int i,best=0;
    for(i=1;i<n;i++)
    {
          if(a[best]<a[i])
               best=i;          
    }
    return best;              
}
int main()
{
    int ben[10],wgt[10],n,i;
    printf("Enter The No Of  Items\n");
    scanf("%d",&n);
    printf("Enter The Values\n");
    for (i = 0; i < n; i++)
      {
      	scanf("%d",&ben[i]);
	  }
	printf("Enter The Weights\n");
	for (i = 0; i < n; i++)
      {
      	scanf("%d",&wgt[i]);
	  }
    int  W ;
    printf("Enter The Capacity Of KnapSack\n");
    scanf("%d",&W);
    float temp[50],sum=0;
    for(i=0;i<5;i++)
          temp[i]=(float)ben[i]/wgt[i];
    while(W>0)
    {
           i=next_best_index(temp,5);
           if(wgt[i]<W)
           {
                   sum=sum+ben[i];
                   W=W-wgt[i];    
           }   
           else
           {
                   sum=sum+temp[i]*W;
                   W=0;
           }
           temp[i]=-1;
    }
    printf("Item   Weight   Benefit    Benefit/Weight\n\n\n");
    for(i=0;i<5;i++)
    {
          printf("ITEM%d %5d %8d %15g\n",i+1,wgt[i],ben[i],(float)ben[i]/wgt[i]);          
    }
    printf("\n\n\nMaximum loot=%g",sum);
    getch();
    return 0;
}
