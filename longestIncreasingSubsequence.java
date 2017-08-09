import java.util.*;

class LIS{
	int [] arr;
	int n;
	
	private void print_arr(int [] lisArr) {
		for(int i=0;i<n;i++) {
			System.out.print(lisArr[i]+" ");
		}
		System.out.println("\n");
	}
	
	int maxLIS() {
		int [] lisArr = new int[n];
		lisArr[0]=1;
		for(int i=1;i<n;i++) {
			lisArr[i]=1;
			int max_val=1;
			boolean changed = false;
			for(int j=0;j<i;j++) {
				if(arr[j]<arr[i]) {
					changed=true;
					if(max_val<lisArr[j]) max_val=lisArr[j];
				}
			}
			if(changed) {
				lisArr[i]=max_val+1;	
			}
		}
		//print_arr(lisArr);
		
		int max=lisArr[0];
		for(int i=1;i<n;i++) {
			if(lisArr[i]>max)max=lisArr[i];
		}
		return max;
	}
}

public class longestIncreasingSubsequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LIS a = new LIS();
		a.n=9;
		int arr[]= {10,22,9,33,21,50,41,60,80};
		a.arr=arr;
		System.out.println(a.maxLIS());
	}

}
