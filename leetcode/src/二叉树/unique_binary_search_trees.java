package 二叉树;

public class unique_binary_search_trees {

	public static void main(String[] args) {
		System.out.println(numTrees(4));
	}
	
	public static int numTrees(int n) {
        if(n<0) return -1;
        if(n==0||n==1) return 1;
        int result=0;
        for(int i=1;i<n;i++) {
        	result+=numTrees(i-1)+numTrees(n-i);
        }
        return result;
    }

}
