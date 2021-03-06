package 排序算法;

public class SelectSort {
	public static void main(String[] args) {
		int[] a= {11,2,3,5,1,2,8,5,6,7,3,23,2,5,3,9,1,33,41,2222};
		selectSort(a);
		print(a);
	}

public static void selectSort(int[] a) {
	int len = a.length;
	for(int i=0;i<len;i++) {
		for(int j=i+1;j<len;j++) {
			if(a[i]>a[j]) {
				swap(a, i, j);
			}
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