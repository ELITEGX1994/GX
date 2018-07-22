package ThreadPool;

public class task5 implements Runnable{
	private int a;
	public task5(int a){
		this.a = a;
	}
	@Override
	public void run() {
		// TODO 自动生成的方法存根
		System.out.println(a);
	}
}
