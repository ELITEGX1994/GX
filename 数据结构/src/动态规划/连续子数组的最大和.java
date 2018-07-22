package 动态规划;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

public class 连续子数组的最大和 {

	public static void main(String[] args) {
		int[] a = {6,-3,-2,7,-15,1,2,2};
		System.out.println(FindGreatestSumOfSubArray1(a));
	}

	public static int FindGreatestSumOfSubArray(int[] a) {
		int max = a[0];
		int result = a[0];
		for(int i=1;i<a.length;i++) {
			max = Math.max(a[i],max+a[i]);
			result = Math.max(result,max);
		}
		return result;
	}
	//
	public static int FindGreatestSumOfSubArray1(int[] a) {
		int[] dp = new int[a.length];
		int max = a[0];
		for(int i=1;i<a.length;i++) {
			dp[i]=Math.max(dp[i-1]+a[i],a[i]);
			max = Math.max(max,dp[i]);
		}
		return max;
	}
}
