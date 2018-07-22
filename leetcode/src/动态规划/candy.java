package 动态规划;

public class candy {

	public static void main(String[] args) {
		int[] ratings = {1,8,3,8,5,10,7};
		System.out.println(candy_sum(ratings));
	}
	
	private static int candy_sum(int[] ratings) {
		int[] candys = new int[ratings.length];
		int sum=0;
		for(int i=0;i<candys.length;i++) {
			candys[i] = 1;
		}
		
		for(int j=1;j<ratings.length;j++) {
			if(ratings[j]>ratings[j-1]) {
				candys[j]=candys[j-1]+1;
			}
		}
		
		for(int k=ratings.length-2;k>=0;k--) {
			if(ratings[k]>ratings[k+1]&&candys[k]<=candys[k+1]) {
				candys[k]=candys[k+1]+1;
			}
		}
		
		for(int i=0;i<ratings.length;i++) {
			sum+=candys[i];
		}
		return sum;
	}
}
