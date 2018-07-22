package 动态规划;

import java.util.ArrayList;

public class palindromePartitioning {
public static void main(String[] args) {
	String s = "aavaa";
	ArrayList<ArrayList<String>> result  = partition(s);
	System.out.println(isPalindrome(s));
	
}

public static ArrayList<ArrayList<String>> partition(String s){
	ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>();
	return result;
}

public static boolean isPalindrome(String s) {
	int len = s.length();
	for(int i=0;i<len/2;i++) {
		if(s.charAt(i) != s.charAt(len-i-1)) {
			return false;
		}
	}
	return true;
}
}
