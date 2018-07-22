package 动态规划;

import java.util.ArrayList;
import java.util.Iterator;

public class Triangle {
	public static void main(String[] args) {
		ArrayList<ArrayList<Integer>> lists = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> list1 = new ArrayList<Integer>();
		list1.add(2);
		ArrayList<Integer> list2 = new ArrayList<Integer>();
		list2.add(3);
		list2.add(4);
		ArrayList<Integer> list3 = new ArrayList<Integer>();
		list3.add(6);
		list3.add(5);
		list3.add(7);
		ArrayList<Integer> list4 = new ArrayList<Integer>();
		list4.add(4);
		list4.add(1);
		list4.add(8);
		list4.add(3);
		lists.add(list1);
		lists.add(list2);
		lists.add(list3);
		lists.add(list4);
		print(lists);
		System.out.println(minimumTotal(lists));
		
	}
	
	private static void print(ArrayList<ArrayList<Integer>> lists) {
		for(ArrayList<Integer> lis:lists) {
			for(Integer i:lis) {
				System.out.print(i+" ");
			}
			System.out.println();
		}
	}
	
	public static int minimumTotal(ArrayList<ArrayList<Integer>> triangle){
		for(int i=triangle.size()-2;i>=0;i--) {
			for(int j=0;j<triangle.get(i+1).size()-1;j++) {
				int e = Math.min(triangle.get(i+1).get(j), triangle.get(i+1).get(j+1)); 
				triangle.get(i).set(j,e+triangle.get(i).get(j));
			}
		}
		return triangle.get(0).get(0);
	}
}

