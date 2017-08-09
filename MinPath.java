import java.util.*;

//Solution was made when i was learning from this course:
//http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/

class minCostPath {
	int n;
	int [][] arr;
	private int [][] min_arr;
	int x,y;

	private int min3(int a, int b, int c) {
		return Math.min(Math.min(a,b),c);
	}
	
	int minCost() {
		min_arr = new int[x+1][y+1];
		min_arr[0][0]=arr[0][0];
		//You can only access the borders from above/left. 
		for(int i=1;i<=x;i++) {
			min_arr[i][0]=min_arr[i-1][0]+arr[i][0];
		}
		for(int i=1;i<=y;i++) {
			min_arr[0][i]=min_arr[0][i-1]+arr[0][i];
		}
		//And the other sections
		for(int i=1;i<=x;i++) {
			for(int j=1;j<=y;j++) {
				min_arr[i][j]=min3(min_arr[i-1][j],min_arr[i-1][j-1],min_arr[i][j-1])+arr[i][j];
			}
		}
		return min_arr[x][y];
	}	
}
//Also i was thinking about bottom-up approach:

class minCostPath2{
	int [][] arr;
	private int [][] min_arr;
	int x,y;
	private int min3(int a, int b, int c) {
		return Math.min(Math.min(a,b),c);
	}
	int minCost2() {
		min_arr = new int[x+1][y+1];
		min_arr[x][y]=arr[x][y];
		//You can only access the borders from above/left. 
		for(int i=x-1;i>=0;i--) {
			min_arr[i][y]=min_arr[i+1][y]+arr[i][y];
		}
		for(int i=y-1;i>=0;i--) {
			min_arr[x][i]=min_arr[x][i+1]+arr[x][i];
		}
		for(int i=x-1;i>=0;i--) {
			for(int j=y-1;j>=0;j--) {
				min_arr[i][j]=min3(min_arr[i+1][j],min_arr[i+1][j+1],min_arr[i][j+1])+arr[i][j];
			}
		}
		
		return min3(min_arr[0][1],min_arr[1][1],min_arr[1][0])+arr[0][0];
	}
}


public class MinPath {

	public static void main(String[] args) {
		minCostPath2 A = new minCostPath2();
		//A.n=3;
		int [][] arr= {{1, 2, 3},{4, 8, 2},{1, 5, 3} };
		A.arr=arr;
		A.x=2;A.y=2;
		System.out.println(A.minCost2());
		// TODO Auto-generated method stub
		
	}

}
