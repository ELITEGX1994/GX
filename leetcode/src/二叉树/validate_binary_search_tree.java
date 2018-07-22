package 二叉树;

public class validate_binary_search_tree {

	public static void main(String[] args) {
		TreeNode root = new TreeNode(2);
		root.left = new TreeNode(1);
		root.right = new TreeNode(3);
		System.out.println(isValidBST(root));
	}
	
	public static boolean isValidBST(TreeNode root) {
        //if(root==null) return true;
        return isValidBSTHelp(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
    }
	
	public static boolean isValidBSTHelp(TreeNode root,int min,int max) {
		if(root==null) return true;
		if(root.val<=min||root.val>=max) return false;
		return isValidBSTHelp(root.left,min,root.val)&&isValidBSTHelp(root.right,root.val,max);
	}
}
