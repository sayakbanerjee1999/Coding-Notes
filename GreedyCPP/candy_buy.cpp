static bool compare(int a, int b){
    return a>b;
}

// For each candy you buy you will get K candies free
vector<int> candyStore(int candies[], int N, int K){
    // Write Your Code here
    sort(candies, candies+N);
    
    int minAmnt = 0;
    int maxAmnt = 0;
    
    int i = 0, j = N-1;
    while(i<=j){
        minAmnt += candies[i];
        i++;
        j -= K;                 // For each candy you buy you will get K candies free
    }
    
    sort(candies, candies+N, compare);
    
    i = 0, j = N-1;
    while(i<=j){
        maxAmnt += candies[i];
        i++;
        j -= K;                 // For each candy you buy you will get K candies free
    }
    
    return {minAmnt, maxAmnt};
}