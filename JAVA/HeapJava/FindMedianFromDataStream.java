class MedianFinder {
    PriorityQueue<Integer> maxHeap;
    PriorityQueue<Integer> minHeap;
    
    /** initialize your data structure here. */
    public MedianFinder() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
      //try to do dry run for clear understading
        maxHeap.offer(num);
        minHeap.offer(maxHeap.poll());
        //so that maxHeap size is always >= minHeap
        if (maxHeap.size()<minHeap.size()){
            maxHeap.offer(minHeap.poll());
        }
    }
    
    public double findMedian() {
        if (maxHeap.size()==minHeap.size())
            return (double)(maxHeap.peek() + minHeap.peek())/2;
        else
            //take the value of the bigger heap which in this case
            //will always be maxHeap - check addNum func
            return maxHeap.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
