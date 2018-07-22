package ThreadPool;

public class task1 implements Runnable{
	@Override
	public void run() {
		// TODO 自动生成的方法存根
		System.out.println(Thread.currentThread().getName()+"hello world");
	}
}
