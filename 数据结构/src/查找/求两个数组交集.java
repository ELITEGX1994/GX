package 查找;

import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class 求两个数组交集 {

	public static void main(String[] args) {
		int[] a = {0,1,2,3,4,9};
		int[] b = {1,3,5,7,9};
		ArrayList<Integer> result = findMixArray1(a, b);
		for(Integer i:result) {
			System.out.println(i);
		}
	}

	//方法一 利用哈希表
	public static ArrayList<Integer> findMixArray(int[] a,int [] b) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		HashMap<Integer, Integer> map = new HashMap<Integer,Integer>();
		for(int i=0;i<a.length;i++) {
			map.put(a[i],1);
		}
		for(int i=0;i<b.length;i++) {
			if(map.containsKey(b[i])) {
				map.put(b[i],2);
			}
			else {
				map.put(b[i],1);
			}
			
		}
		for(Map.Entry<Integer, Integer>entry:map.entrySet()) {
			if(entry.getValue()==2) {
				result.add(entry.getKey());
			}
		}
		return result;
	}
	
	//方法二使用merge
	public static ArrayList<Integer> findMixArray1(int[] a,int[] b){
		ArrayList<Integer> result = new ArrayList<Integer>();
		int i=0;
		int j=0;
		while(i<a.length&&j<b.length) {
			if(a[i]==b[j]) {
				result.add(a[i]);
				i++;
				j++;
			}
			else if(a[i]>b[j]) {
				j++;
			}else if(a[i]<b[j]) {
				i++;
			}
		}
		return result;
	}
}
