package ջ;
import java.util.*;
public class TestStack {
	public static int get(Stack<Integer> stack) {
		int result = stack.pop();
		if(stack.isEmpty()) return result;
		else {
			int last=get(stack);
			stack.push(result);
			return last;
		}
		
	}
	
	public static void getNochange(Stack<Integer> stack) {
		int result = stack.pop();
		if(stack.isEmpty()) System.out.println(result);
		else {
			getNochange(stack);
		}
		stack.push(result);
	}
	
	public static void reverse(Stack<Integer> stack)
	{
		if(stack.isEmpty()) return;
		int i=get(stack);
		reverse(stack);
		stack.push(i);
	}
	
	public static Stack<Integer> sort(Stack<Integer> stack)
	{
		Stack<Integer> help = new Stack<Integer>();
		int first = stack.pop();
		help.push(first);
		while(!stack.isEmpty()) {
			int a = stack.pop();
			while(!help.isEmpty())
			{
				int b=help.pop();
				if(a>b) {
					help.push(a);
					stack.push(b);
				}
				else{
					help.push(b);
					help.push(a);
				}
				
			}
		}
		return help;
		
	}
	
	public static void main(String[] args)
	{
	
		Stack<Integer> s = new Stack<Integer>();
		Stack<Integer> sort = new Stack<Integer>();
		s.push(3);
		s.push(2);
		s.push(1);
		//getNochange(s);
		sort = sort(s);
		while(!sort.isEmpty()) {
			System.out.println(sort.pop());
		}
		/*
		int out = get(s);
		System.out.println(out);
		*/
		/*
		reverse(s);
		while(!s.isEmpty()) {
			System.out.println(s.pop());
		}*/
	}

}
