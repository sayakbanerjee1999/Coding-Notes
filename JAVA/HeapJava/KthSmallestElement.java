class Solution{
    public static int kthSmallest(int[] arr, int l, int r, int k) 
    { 
        //Your code here
        PriorityQueue<Integer> maxH = new PriorityQueue<>(Collections.reverseOrder());
        for (int i=0;i<=r;i++){
            maxH.offer(arr[i]);
            if (maxH.size()>k)
                maxH.remove();
        }
        return maxH.peek();
    } 
}
