package 普通;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class 按字典序全排列 {
		public static int total = 0;  
		public static void main(String[] args) {
			 ArrayList<String> lists = new ArrayList<String>();
	         String s = "acbbb"; 
	         char[] chs = s.toCharArray();
	         Arrays.sort(chs);
	         System.out.println(chs);
	         quanpailie(chs, 0, chs.length,lists);
	         System.out.pr intln("全排列个数为:"+total);
	         /*
	         for(String l:lists) {
	        	 System.out.println(l);
	         }
	         */
	         HashSet<String> sets = new HashSet<String>();
	         sets.addAll(lists);
	         for(String set:sets) {
	        	 System.out.println(set);
	         }
		}
		
		public static void quanpailie(char[] chs,int start,int len,ArrayList<String> lists) {
			String s="";
			if(start==len-1) {
				for(int i=0;i<len;i++) {
					s+=chs[i];
				}
				total++;
			    lists.add(s);
			}else {
				for(int i=start;i<len;i++) {
					swap(chs, start, i);
					quanpailie(chs, start+1, len, lists);
					swap(chs,start,i);
				}
			}
			
		}

		public static void swap(char[] chs, int i, int j)  
	    {  
	        char temp = '1';  
	        temp = chs[i];  
	        chs[i] = chs[j];  
	        chs[j] = temp;  
	    } 
	}