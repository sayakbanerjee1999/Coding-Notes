class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        if (k==nums.length)
            return nums;
        
        //putting the element and their frequency in hashmap
        Map<Integer,Integer> count= new HashMap<>();
        for (int n:nums){
            count.put(n, count.getOrDefault(n,0)+1);
        }
        
        //Priority Q to compare nums by their frequency 
        Queue<Integer> heap = new PriorityQueue<>(
        (n1,n2)-> count.get(n2)-count.get(n1));
        
        //add nums to the q
        for (int n : count.keySet()){
            heap.add(n);
        }
        
        //get the top k elements
        int[] top = new int[k];
        for (int i=k-1;i>=0;i--){
            top[i] = heap.poll();
        }
        return top;
    }
}
