package 普通;

import java.util.ArrayList;
import java.util.HashSet;

public class 全排列 {
	public static int total = 0;  
	public static void main(String[] args) {
		 ArrayList<String> lists = new ArrayList<String>();
         String str[] = {"1","2","3"};  
         quanpailie(str, 0, str.length,lists);
         System.out.println("全排列个数为:"+total);
         for(String s:lists) {
        	 System.out.println(s);
         }
	}
	
	public static void quanpailie(String[] str,int start,int len,ArrayList<String> lists) {
		String s="";
		if(start==len-1) {
			for(int i=0;i<len;i++) {
				s+=str[i];
			}
			total++;
		    lists.add(s);
		}else {
			for(int i=start;i<len;i++) {
				swap(str, start, i);
				quanpailie(str, start+1, len, lists);
				swap(str,start,i);
			}
		}
		
	}

	public static void swap(String[] str, int i, int j)  
    {  
        String temp = new String();  
        temp = str[i];  
        str[i] = str[j];  
        str[j] = temp;  
    } 
}
