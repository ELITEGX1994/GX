package 查找;

import java.util.function.IntPredicate;

public class 查找数组中逆序对的对数 {
	public static int count=0;;
	public static void main(String[] args) {
		//int[] a = {5,8,3,6};
		int[] a = {1,5,3,2,6};
		MergeSort(a);
		System.out.println(count);
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
			//help[i++]=a[p1]<a[p2]?a[p1++]:a[p2++];
			
			if(a[p1]<=a[p2]) {
				help[i++]=a[p1++];
			}
			else {
				help[i++]=a[p2++];
				count+=mid-p1+1;
			}
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
}
