package 查找;

import java.util.ArrayList;

public class TopK {

	public static void main(String[] args) {
		int[] a = { 50, 10, 90, 30, 70,1231,1111, 40, 80, 60, 20 };
		ArrayList<Integer> result = findTopK(a,2);
		for(Integer i:result) {
			System.out.println(i);
		}
	}
	/*
	public static int[] findTopK(int[] a,int k) {
		buildHeap(a);
		for(int i=a.length-1;i>a.length-1-k;i--)
		{
			swap(a,0,i);
			heapAdjust(a, 0, i);
		}
		
		int[] Ks = new int[k];
		for(int j=0;j<k;j++) {
			Ks[j]=a[a.length-1-j]; 
		}
		return Ks;
	}
	*/
	public static ArrayList<Integer> findTopK(int[] a,int k) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		buildHeap(a);
		for(int i=a.length-1;i>a.length-1-k;i--)
		{
			swap(a,0,i);
			heapAdjust(a, 0, i);
			result.add(a[i]);
		}
		return result;
	}
	public static void buildHeap(int[] a) {
		for(int i=a.length/2;i>=0;i--) {
			heapAdjust(a,i,a.length);
		}
	}
	

	public static void heapAdjust(int[] a, int i, int length) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;
        if (left < length && a[left] > a[i]) {
            largest = left;
        }
        if (right < length && a[right] > a[largest]) {
            largest = right;
        }
        if (i != largest) {
            swap(a, largest, i);
            heapAdjust(a, largest, length);
        }
    }
	
	private static void swap(int[] arr, int index1, int index2) {
		int tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}
}
