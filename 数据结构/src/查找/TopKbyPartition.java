package 查找;

import javax.naming.spi.DirStateFactory.Result;

public class TopKbyPartition {

	public static void main(String[] args) {
		int[] a = { 50, 10, 90, 30, 70,1231,1111, 40, 80, 60, 20 };
		int[] Ks = findPos(a, 6);
		for(int i=0;i<Ks.length;i++) {
			System.out.println(Ks[i]);
		}
	}
	
	public static int[] findPos(int[] a,int k) {
		int low=0;
		int high=a.length-1;
		int[] result = new int[k];
		int pos = Partition(a,low,high);
		while(pos!=k-1) {
	    //大了，往前调整
		if(pos>k-1) {
			high=pos-1;
			pos=Partition(a, low, high);
		}
		//小了往后调整
		if(pos<k-1) {
			low=pos+1;
			pos=Partition(a, low, high);
		}
	}
		for(int i=0;i<k;i++) {
			result[i]=a[i];
		}
		return result;
	}
	
	public static int Partition(int[] a,int low,int high) {
		int key=a[low];
		while(low<high) {
			while(low<high&&a[high]<=key) {
				high--;
			}
			a[low]=a[high];
			while(low<high&&a[low]>=key) {
				low++;
			}
			a[high]=a[low];
		}
		a[low]=key;
		return low;
	}

}
