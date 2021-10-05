import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=0;i<t;i++){
		    int n = sc.nextInt();
		    int k = sc.nextInt();
		    int[] arr = new int[n];
		    for (int j=0;j<n;j++){
		        arr[j] = sc.nextInt();
		    }
		    helper(arr,n,k);
		}
	}
	public static void helper(int[] arr, int n, int k){
	    PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
	    int[] res = new int[n];
	    int index = 0;
	    for (int i=0;i<n;i++){
	        pq.add(arr[i]);
	        if(pq.size()>k){
	            res[index] = pq.peek();
	            pq.remove();
	            index++;
	        }
	    }
	    while(!pq.isEmpty()){
	        res[index] = pq.peek();
	        index++;
	        pq.remove();
	    }
	    for (int i=0;i<n;i++){
	        System.out.print(res[i]+" ");
	    }
	    System.out.println();
	}
}
