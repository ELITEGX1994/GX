package 查找;

public class 统计单词个数 {

	public static void main(String[] args) {
		String s = "i   am wondeful!";
		System.out.println("单词个数为："+wordCount(s));
	}
	
	public static int wordCount(String s) {
		int word =0;
		int count = 0;
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)==' ') {
				word = 0;
			}
			//若word=0表示前一个字符为空格，若为1前一个字符非空格
			else if(word == 0) {
				word =1;
				count++;
			}
		}
		return count;
	}

}
