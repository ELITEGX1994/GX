package ThreadPool;

import java.util.concurrent.Callable;

public class task4 implements Callable<Integer> {
	private int a;
	public task4(int a) {
		this.a = a;
	}
	
	public Integer call() {
		int sum=0;
		for(int i=1;i<=a;i++) {
			sum+=i;
		}
		return sum;
	}
}
