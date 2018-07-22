package 排序算法;

public class MergeSort {

	public static void main(String[] args) {
		int[] a= {11,2,3,5,1,2,8,5,6,7,3,23,2,5,3,9,1,33,41,2222};
		MergeSort(a);
		print(a);
	}

	public static void MergeSort(int[] a)
	{
		if(a == null||a.length<2) return;
		Sort(a,0,a.length-1);
	}
	
	public static void Sort(int[] a,int low,int high)
	{
		if(low==high) return;
		int mid = (low+high)/2;
		Sort(a,low,mid);
		Sort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
	
	public static void Merge(int[] a,int low,int mid,int high)
	{
		int[] help=new int[high-low+1];
		int i=0;
		int p1=low;
		int p2=mid+1;
		while(p1<=mid&&p2<=high){//�ѽ�С�������Ƶ���������
			help[i++]=a[p1]<a[p2]?a[p1++]:a[p2++];
		}
		while(p1<=mid){//�����ʣ������������� 
			help[i++] = a[p1++];
		}
		while (p2 <= high) {//���ұ�ʣ�������������
			help[i++] = a[p2++];
		}
		for(i=0;i<help.length;i++) //���������е�������array����
		{
			a[i+low]=help[i];
		}
	} 
	
	public static void print(int[] a) {
		for(int i=0;i<a.length;i++) {
			System.out.print(a[i]+" ");
		}
	}
}
