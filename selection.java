import java.io.*;
public class selection 
{
	public static void main(String args[])throws IOException
	{
		selection o=new selection();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the Size of array");
		int n=Integer.parseInt(br.readLine());
		int a[]=new int[n];
		System.out.println("Enter the element of array");
		for(int i=0;i<n;i++)
		{
			a[i]=Integer.parseInt(br.readLine());
		}
		System.out.println("The Array Before Sorting");
		o.printarray(a, n);
		o.sortarray(a,n);
		System.out.println("The Array After Sorting");
		o.printarray(a,n);
	}

	private void printarray(int a[], int n) 
	{
		for(int i=0;i<n;i++)
		{
			System.out.println(" "+a[i]);
		}
	}

	private void sortarray(int a[], int n)
	{
		for(int i=0;i<n-1;i++)
		{
			int min=i;
			for(int j=i+1;j<n;j++)
			{
				if(a[j]<a[min])
					min=j;
			}
			int t=a[min];
			a[min]=a[i];
			a[i]=t;
		}
	}
}
