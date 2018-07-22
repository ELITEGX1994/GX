package 模拟;

import java.util.ArrayList;
import java.util.Scanner;

public class PascalsTriangle {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		//ArrayList<Integer> list = new ArrayList<Integer>();
		ArrayList<ArrayList<Integer>> lists = generate(k);
		
		for(ArrayList<Integer> list:lists)
		{
			for(Integer i:list)
			{
				System.out.print(i+" ");
			}
			System.out.println();
		}
	}
	
	public static ArrayList<ArrayList<Integer>> generate(int numRows) {
        ArrayList<ArrayList<Integer>> lists = new ArrayList<ArrayList<Integer>>();
        //ArrayList<Integer> list = new ArrayList<Integer>();
        numRows++;
		if(numRows==0) return lists;
		list.add(1);
		lists.add(list);
		if(numRows==1) return lists;
		for(int i=0;i<numRows;i++) 
		{
			ArrayList<Integer> list = new ArrayList<Integer>();
			for(int j=0;j<) 
			{
				list.add()
			}
			lists(list);
		}
		return lists;
	}
	
	public abstract class MyClass{
		public int contInt = 5;
		public abstract void method(int a);
		public void method() {}
	}
}
