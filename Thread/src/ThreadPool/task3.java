package ThreadPool;

import java.beans.IntrospectionException;
import java.util.concurrent.Callable;

public class task3 implements Callable<Integer> {
	public Integer call() {
		Integer a = new Integer(15);
		return a;
	}
}
