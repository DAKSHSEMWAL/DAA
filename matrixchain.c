#include<stdio.h>
#include<limits.h>

int MatrixChainOrder(int p[], int n)
{
    int m[n][n],s[n][n];
    int i,j,k,l,q;
    n=n-1;
    for(i=0;i<=n;i++)
    m[i][i]=0;
    for(l=2;l<=n;l++)
    { 
	    for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
    		m[i][j]=9999999;
            for(k=i;k<=j-1;k++)
			{
            	q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            	if(q<m[i][j])
            	{
			    	m[i][j]=q;
                	s[i][j]=k;
            	}
        	}
   		}
    }
    printf("\n The M matrix is:\n");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		printf("%d\t",m[i][j]);
		}
		printf("\n\n");
	}
	printf("\nThe S Matrix is:\n");
	    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		printf("%d\t",s[i][j]);
		}
		printf("\n\n");
	}
    return m[1][n-1];
}

 int main()
{
    int arr[100],i,j,k,n;
    printf("Enter the Size of Array\n");
    scanf("%d",&n);
    printf("\nEnter the Elements of Array\n");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
 	printf("\nMinimum number of multiplications is %d ",
    MatrixChainOrder(arr,n));
    getchar();
    return 0;
}
