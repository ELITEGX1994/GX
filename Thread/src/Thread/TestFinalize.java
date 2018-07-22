package Thread;  
class TestGC { 
  private String str = "hello"; 
     
  TestGC(String str) { 
    this.str = str; 
  } 
     
  public void finalize() { 
    System.out.println(str); 
  } 
} 
     
public class TestFinalize { 
  /** 
   * @param args 
   */
  public static void main(String[] args) { 
    // TODO 自动生成方法存根 
    System.out.println("hello"); 
     
    TestGC test = new TestGC("test1"); 
    test = new TestGC("test2"); 
    test = null;//注释掉这一句，test1被回收。加上则先回收test2,后test1 
    System.gc(); 
  } 
}