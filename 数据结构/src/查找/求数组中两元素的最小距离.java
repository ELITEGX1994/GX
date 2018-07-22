package 查找;

public class 求数组中两元素的最小距离 {

	public static void main(String[] args) {
		int[] a = {4,5,6,4,7,4,6,4,7,8,5,6,4,3,10,8};
		System.out.println(minDistance(a,4,8));
	}
	
	public static int minDistance(int[] a,int n1,int n2) {
		if(a==null) return -1;
		int minDistance = Integer.MAX_VALUE;
		int n1Index= -1;
		int n2Index= -1;
		for(int i=0;i<a.length;i++) {
			if(a[i]==n1) {
				n1Index=i;
				if(n2Index>=0)
					minDistance = Math.min(Math.abs(minDistance),Math.abs(n1Index-n2Index));
			}
			if(a[i]==n2) {
				n2Index = i;
				if(n1Index>=0)
					minDistance = Math.min(Math.abs(minDistance),Math.abs(n1Index-n2Index));
			}
		}
		return minDistance;
	}
}
