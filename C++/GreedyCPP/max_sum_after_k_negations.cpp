long long int maximizeSum(long long int a[], int n, int k){
    // Your code goes here
    sort(a, a+n);
    
    long long int sum = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i]<0 && k>0){
            a[i] = -a[i];
            k--;
        }
    }
    
    for(int i = 0; i < n; i++)
        sum += a[i];
    
    // Perform only if k>0 and k is odd. if k is odd then only sign will get changed
    if(k>0 && k%2!=0){
        int x = *min_element(a, a+n);
        sum -= 2*x;
    }
    
    return sum;
}