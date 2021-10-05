class Solution {
// custom Pair class having distance and the coordinate values
class Pair{
    int arr[] = new int[2];
    int dis;
    
    Pair(int dis, int arr[]){
        this.dis = dis;
        this.arr[0] = arr[0];
        this.arr[1] = arr[1];
    }
}

public int[][] kClosest(int[][] arr, int k) {
    int n = arr.length;
    int ans[][] = new int[k][2];
    
    // custom max heap where comparator used to sort by the euclidean distance
    PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>(){
        public int compare(Pair a, Pair b){
            return b.dis - a.dis;
        }
    });
    
    // adding values in Priority Queue
    for(int i=0; i<n; i++){
        int temp[] = new int[2];
        temp[0] = arr[i][0];
        temp[1] = arr[i][1];
        int dis = (int)Math.pow(temp[0], 2) + (int)Math.pow(temp[1], 2);
        
        pq.add(new Pair(dis, temp));
        if(pq.size() > k)
            pq.poll();
    }
    
    // popping values from Priority Queue to ans[][]
    for(int i=0; i<k; i++){
        ans[i][0] = pq.peek().arr[0]; 
        ans[i][1] = pq.peek().arr[1];
        
        pq.poll();
    }
    
    return ans;
}
}
