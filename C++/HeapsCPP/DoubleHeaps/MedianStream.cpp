class MedianFinder {
private:
    priority_queue<int> small;       // small -> carries smaller numbers (maxHeap)
    priority_queue<int, vector<int>, greater<int>> large;    // large -> carries larger numbers (minHeap)

// MEDIAN IN A STREAM (LOG N)

// 1. Maintain 2 heaps (small heap <maxHeap>, large heap<minHeap>)
//     1. At all times we have to maintain 2 conditions 
//         1. All number in small heap must be <= all numbers in large heap
//         2. Size of small heap ~ size of large heap (at any time the size of a heap can only be +1 from the other heap)
//     2. These conditions make sure that at the end of insertion phase.
//         1. If size of one heap > size of other heap
//             1. It has odd number of elements and the top of heap with greater size is the median
//         2. Else if size equal; median = 1/2(top(A)+top(B))

// Algorithm
// 1. Void addNUM()
//     1. By default add the number to the small (maxH)
//     2. Check if all numbers in the small (maxH) is <= all numbers in large (minH). If small.top() > large.top() [condition Violated]
//         1. Pop from small Heap and push to the large heap
//     3. Check if all size of small > large + 1. Pop from small and push to large. Small greater in size
//     4. Check if all size of large > small + 1. Pop from large and push to small. Large is greater in size.
// 2. Int return_median()
//     1. If any of the heaps are larger than the other (Odd number of elements). Return the top of the heap with more elements. (That's the middle one)
//     2. Otherwise return the avg of the top of both heaps (Even number of elements. 

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // By default add the number to the small (maxH)
        small.push(num);

        // Check if all numbers in the small (maxH) is <= all numbers in large (minH). Pop from small Heap and push to the large heap  
        if(!small.empty() && !large.empty() && small.top() > large.top()){
            int top = small.top();
            small.pop();
            large.push(top);
        }

        // Check if all size of small > large + 1. Pop from small and push to large
        if (small.size() > large.size()+1){
            int top = small.top();
            small.pop();
            large.push(top);
        }

        // Vice Versa
        if(large.size() > small.size()+1){
            int top = large.top();
            large.pop();
            small.push(top);
        }
    }
    
    double findMedian() {
        // If any of the heaps are larger than the other (Odd number of elements). Return the top of the heap with more elements. (That's the middle one)
        if(small.size() > large.size())
            return small.top();
        if(small.size() < large.size())
            return large.top();
        
        // Otherwise return the avg of the top of both heaps (Even number of elements)
        return (large.top() + small.top())/2.0;
    }
};
