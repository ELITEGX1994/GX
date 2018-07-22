package 普通;

import java.awt.List;
import java.io.BufferedWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;

public class 组合 {
	    public static int total = 0;  
	    public static void swap(String[] str, int i, int j)  
	    {  
	        String temp = new String();  
	        temp = str[i];  
	        str[i] = str[j];  
	        str[j] = temp;  
	    } 
	    //start为起始位置,len为排列序列长度
	    public static void combine (String[] str, int start, int len,HashSet<String> sets)  
	    {  
	    	String s="";
	        if (start == len - 1)  
	        {  
	            for (int i = 0; i < len; i ++)  
	            {  
	                //System.out.print(str[i]+ "");
	            	s+=str[i];
	            }
	            sets.add(s);
	            //System.out.println();  
	            //total++;  
	        }  
	        else  
	        {  
	            for (int i = start; i < len; i ++)  
	            {   
	                swap(str, start, i);  
	                combine(str, start + 1, len,sets);  
	                swap(str, start, i);  
	            }  
	        }  
	        //sets.add(s);  
	    }  
	    /** 
	     * @param args 
	     */ 
	    
	    
	    public static void main(String[] args) {
	    	HashSet<String> sets = new HashSet<String>();
	        // TODO Auto-generated method stub  
	         String str[] = {"1","2","3"};  
	         combine(str, 0, str.length,sets);  
	        // System.out.println(total); 
	         for(String s:sets) {
	        	 System.out.println(s);
	         }
	    }  
	}  
