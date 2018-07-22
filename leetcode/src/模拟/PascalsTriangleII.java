package 模拟;

import java.util.ArrayList;
import java.util.Scanner;

import org.omg.CORBA.PUBLIC_MEMBER;

public class PascalsTriangleII {
	public static ArrayList<Integer> getRaw(int rowIndex){
		ArrayList<Integer> list = new ArrayList<Integer>();
		rowIndex++;
		if(rowIndex==0) return list;
		list.add(1);
		//i表示第i次的链表状态
		for(int i=1;i<rowIndex;i++) {
			//j表示第链表中第j个数
			for(int j=i-1;j>0;j--) {
				list.set(j, list.get(j-1)+list.get(j));
			}
			list.add(1);
		}
		//list.add(1);
		return list;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		//ArrayList<Integer> list = new ArrayList<Integer>();
		ArrayList<Integer> list = getRaw(k);
		for(Integer i:list) {
			System.out.println(i);
		}
	}
}
