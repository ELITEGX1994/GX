package ThreadPool;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class gxThreadPool {
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		//ExecutorService pool = new newFixedThreadPool(5);
		//ExecutorService es = Executors.newFixedThreadPool(2);
		 ExecutorService es = Executors.newFixedThreadPool(2);
		//System.out.println(es);
		es.submit(new task1());
		es.submit(new task5(100));
		//es.submit(new task2());
		//es.submit(new task2());
		es.submit(new task2());
		Future<Integer> f1 = es.submit(new task4(100));
		Future<Integer> f2 = es.submit(new task4(200));
		System.out.printf("1+...+100= "+f1.get()+"\n"+"1+...+200= "+f2.get()+"\n");
		/*
		try{
			System.out.println(f.get());
		}
		catch (ExecutionException e) {
			// TODO: handle exception
			e.printStackTrace();
		}
		catch(InterruptedException e) {
			e.printStackTrace();
		}
		*/
}

}
