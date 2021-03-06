package 排序算法;

public class QuckSort {

	public static void main(String[] args) {
		int[] a= {11,2,3,5,1,2,8,5,6,7,3,23,2,5,3,9,1,33,41,2222};
		quickSort(a,0,a.length-1);
		print(a);
	}
	
	
	public static void quickSort(int[] a,int low,int high) {
		if(low>=high){
            return ;
        }
		int index=partition(a,low,high);
	    quickSort(a,low,index-1);
	    quickSort(a,index+1,high); 
		
	}
	
	public static int partition(int []a,int low,int high){
        int key=a[low];
        while(low<high){
            while(a[high]>=key&&high>low){
                high--;
            }
            a[low]=a[high];
            while(a[low]<=key&&high>low){
                low++;
            }
            a[high]=a[low];
        }
        a[low]=key;
        return low;
    }
	
	public static void print(int[] a) {
		for(int i=0;i<a.length;i++) {
			System.out.print(a[i]+" ");
		}
	} 
}
