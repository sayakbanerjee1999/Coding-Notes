class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        for(auto task: tasks){
            if(map.find(task) == map.end())
                map[task] = 1;
            else
                map[task]++;
        };
        
        // We will always do the most frequent task first to reduce idle time
        priority_queue<int> maxH;
        for(auto it: map)
            maxH.push(it.second);
        
        // In the queue we will be storing the remaining frequency of the task and the next time when it is available to be put in CPU 
        // (then we will push it back to the heap)
        queue<pair<int, int>> q;
        int time = 0;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        while(!maxH.empty() || !q.empty()){
            time += 1;

            // Take the most frequent empty from the heap and decrement count and push to Queue with updated available time
            if(!maxH.empty()){
                int freq = maxH.top();
                maxH.pop();
                int updatedFreq = freq-1;

                // Available time = current time + n
                if (updatedFreq > 0)
                    q.push({time+n, updatedFreq});
            }

            // The front of the queue will always have the element that might be available 
            // (because every job has the fixed downtime -> availability time will always in increasing order). 
            // If jobs have different down time, we can use another min pq (first element will be availability time)
            // Makes sure of the idle time as well as though queue will have element the maxH will not have.
            if(!q.empty() && q.front().first == time){
                // The process is available and now be pushed 
                auto it = q.front();
                q.pop();
                maxH.push(it.second);
            }
        }

        return time;
    }

    // Only change if using a priority queue is front replaced by top.
};
