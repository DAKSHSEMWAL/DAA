import java.io.*;
public class matrixchain
{
	public static void main(String args[])throws IOException
	{
		matrixchain o=new matrixchain();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the Size of Array");
		int n=Integer.parseInt(br.readLine());
		int a[]=new int[n];
		System.out.println("Enter the ELements of the Arrray");
		for(int i=0;i<n;i++)
		{
			a[i]=Integer.parseInt(br.readLine());
		}
		int c=o.MatrixChainOrder(a,n);
		System.out.println("Minimum number of Multiplications isC"+c);
	}
		int MatrixChainOrder(int p[], int n)
	    {
	        int m[][] = new int[n][n];
	 
	        int i, j, k, L, q;
	        for (i = 1; i < n; i++)
	            m[i][i] = 0;
	        for (L=2; L<n; L++)
	        {
	            for (i=1; i<n-L+1; i++)
	            {
	                j = i+L-1;
	                if(j == n) continue;
	                m[i][j] = Integer.MAX_VALUE;
	                for (k=i; k<=j-1; k++)
	                {
	                    q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
	                    if (q < m[i][j])
	                        m[i][j] = q;
	                }
	            }
	        }
	        return m[1][n-1];
	    }
	}


