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
    // TODO �Զ����ɷ������ 
    System.out.println("hello"); 
     
    TestGC test = new TestGC("test1"); 
    test = new TestGC("test2"); 
    test = null;//ע�͵���һ�䣬test1�����ա��������Ȼ���test2,��test1 
    System.gc(); 
  } 
}