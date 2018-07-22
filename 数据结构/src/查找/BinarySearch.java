package 查找;

public class BinarySearch {
public static void main(String[] args) {
	int[] a = {1,3,5,7,7,9,10};
	System.out.println(binarySearch(a, 5));
}

public static int binarySearch(int[] a,int key) {
	int low=0;int high=a.length-1;int mid;
	while(low<=high) {
		mid = (low+high)/2;
		if(a[mid] == key) return mid;
		if(a[mid] > key) high = mid-1;
		if(a[mid] < key) low = mid+1;
	}
	return -1;
}
}
