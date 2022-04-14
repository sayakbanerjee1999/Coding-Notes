class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minH;
        
        for(long long i = 0; i < n; i++){
            minH.push(arr[i]);
        }
        
        long long cost = 0;
        while(minH.size() > 1){
            long long a = minH.top();
            minH.pop();
            long long b = minH.top();
            minH.pop();
            
            cost = cost + (a+b);
            
            minH.push(a+b);
        }
        
        return cost;
    }
};
