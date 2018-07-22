package 贪心算法;

import javax.print.attribute.standard.RequestingUserName;

import org.ietf.jgss.GSSContext;

public class gasstation {

	public static void main(String[] args) {
		int[] gas = {1,3,4,5,7,2};
		int[] cost = {6,2,4,5,3,2};
		System.out.println(canCompleteCircuit1(gas, cost));
	}

	private static int canCompleteCircuit(int[] gas, int[] cost) {
		int left = 0;//剩余的油量
		for(int i=0;i<gas.length;i++) {
			for(int j=0;j<gas.length;j++) {
				//精髓步骤，用（i+j）%length来模拟环
				left=left+gas[(i+j)%gas.length]-cost[(i+j)%gas.length];
			if(left<0) {left=0;break;}
			if(j==gas.length-1)  return i;
			}
		}
		return -1;
	}
	
	private static int canCompleteCircuit1(int[] gas, int[] cost) {
	int start=gas.length-1;
	int end=0;
	int left=gas[start]-cost[start];
	while(end<start) {
		if(left>=0) {
			left+=gas[end]-cost[end];
			end++;
		}else {
			start--;
			left+=gas[start]-cost[start];
		}
	}
	return left>=0?start:-1;
	}
}
