package 普通;

import java.util.function.IntToDoubleFunction;

public class decode_ways {
/*
	A message containing letters fromA-Zis being encoded to numbers using the following mapping:

		'A' -> 1
		'B' -> 2
		...
		'Z' -> 26
		Given an encoded message containing digits, determine the total number of ways to decode it.

		For example,
		Given encoded message"12", it could be decoded as"AB"(1 2) or"L"(12).

		The number of ways decoding"12"is 2.
*/

	public static void main(String[] args) {
		System.out.println(numDecodings("104"));
	}

	public static int numDecodings(String s) {
	int len = s.length();
	if(s.length()==0 || s.charAt(0)=='0')
            return 0;
	char[] chs = s.toCharArray();
	/** 
	dp[i] 表示i的字符的合法编码数量，取决于当前字符
	dp[i] += dp[i-1],if s[i-1] ~('0'--'9')或者s[i-1]!='0';
	dp[i] += dp[i-2],if s[i-2] == '1' || (s[i-2]=='2' && s[i-1]>='0' && s[i-1]<='6')
	**/
	  int[] dp= new int[len+1];
	  dp[0]=1;dp[1]=1;
	  for(int i=2;i<dp.length;i++) {
		  if(chs[i-1]>='1'&&chs[i-1]<='9') {
			  dp[i]=dp[i-1];
		  }
		  if(chs[i-2]=='1'||(chs[i-2]=='2'&&chs[i-1]>='0'&&chs[i-1]<='6')) {
			  dp[i]+=dp[i-2];//这一步不是很懂
		  }
	  }
	  return dp[len];
    }
}
