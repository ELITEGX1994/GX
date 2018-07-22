package 二叉树;

import java.util.ArrayList;

public class Unique_binary_search_trees_ii {

	public static void main(String[] args) {
		ArrayList<TreeNode> result = generateTrees(3);
	}
	public static ArrayList<TreeNode> generateTrees(int n) {
		return generateHelper(1,n);
    }
	
	public static ArrayList<TreeNode> generateHelper(int low,int high) {
		ArrayList<TreeNode> result = new ArrayList<TreeNode>();
        if(low>high) return result;
        for(int i=low;i<=high;i++) {
        	ArrayList<TreeNode> left = generateHelper(low, i-1);
        	ArrayList<TreeNode> right = generateHelper(i+1, high);
        	for(int j=0;j<left.size();j++) {
        		for(int k=0;k<right.size();k++) {
        			TreeNode root = new TreeNode(i);
        			root.left = left.get(j);
        			root.right = right.get(k);
        			result.add(root);
        		}
        	}
        }
        return result;
    }	
}
