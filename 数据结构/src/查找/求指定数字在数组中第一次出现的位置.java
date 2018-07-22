package 查找;

import javax.print.attribute.standard.RequestingUserName;

public class 求指定数字在数组中第一次出现的位置 {

	public static void main(String[] args) {
		int[] a = {3,4,5,6,5,7,8,9,8};
		System.out.println(findIndex(a, 5));
	}
	
	public static int findIndex(int[] a,int t) {
		if(a==null) return -1;
		int i=0;
		while(i<a.length) {
			if(a[i]==t) {return i;}
			else {i+=Math.abs(t-a[i]);}
		}
		return -1;
	}
}