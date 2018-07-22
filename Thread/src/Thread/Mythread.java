package Thread;

public class Mythread extends Thread{
    public static void main(String[] args) {
        Mythread t=new Mythread();
        Mythread s=new Mythread();
        t.start();
        System.out.println("one.");
        s.start();
        System.out.println("two.");
    }
    public void run() {
        System.out.println("Thread");
    }
}