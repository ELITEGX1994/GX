package 排序算法;

public class BubbleSort {

	public static void main(String[] args) {
		int[] a= {11,2,3,5,1,2,8,5,123,6,7,3,23,2,5,3,9,1,33,41,2222};
		maoPao(a);
		print(a);
	}

	public static void maoPao(int[] array)
	{
		int len = array.length;
		for(int i=0;i<len;i++)
		{
			for(int j=len-2;j>=i;j--)
			{
				if(array[j]>array[j+1])
					swap(array, j, j+1);
			}
		}
	}
	
	public static void swap(int[] a,int i,int j) {
		a[i] = a[i]^a[j];
		a[j] = a[i]^a[j];
		a[i] = a[i]^a[j];
	}
	
	public static void print(int[] a) {
		for(int i=0;i<a.length;i++) {
			System.out.print(a[i]+" ");
		}
	}
}
