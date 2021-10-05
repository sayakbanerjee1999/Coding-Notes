long long minCost(long long arr[], long long n) {
    // At every point we have to select the two minimum number
    priority_queue<long long, vector<long long>, greater<long long>> minH;
    
    
    for(long long i = 0; i < n; i++){
        minH.push(arr[i]);
    }
    
    long long cost = 0;
    while(minH.size()>=2){
        long long a = minH.top(); 
        minH.pop();
        long long b = minH.top(); 
        minH.pop();
        
        cost = cost + a + b;
        minH.push(a+b);
    }
    
    return cost;
}