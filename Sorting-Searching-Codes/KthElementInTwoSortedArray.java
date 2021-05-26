class Solution {
    public long kthElement( int arr1[], int arr2[], int n, int m, int k) {
        
        // Declaring a min heap
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Pushing elements for 
        // array a to min-heap
        for (int i = 0; i < n; i++) {
            pq.offer(arr1[i]);
        }

        // Pushing elements for 
        // array b to min-heap
        for (int i = 0; i < m; i++) {
            pq.offer(arr2[i]);
        }

        // Poping-out K-1 elements
        while (k-- > 1) {
            pq.remove();
        }
        return pq.peek();
    }
}
