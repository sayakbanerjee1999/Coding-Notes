long long int maxSum(int arr[], int n){
    sort(arr, arr + n);
    
    vector<int> v;
    for(int i = 0; i < n/2; i++){
        v.push_back(arr[i]);
        v.push_back(arr[n-i-1]);
    }
    
    // If there are odd elements, push the
    // middle element at the end.
    if (n % 2 != 0)
        v.push_back(arr[n/2]);
    
    long long int sum = 0;
    
    for(int i = 0; i < n-1; i++){
        sum = sum + abs(v[i]-v[i+1]);
    }
    
    sum = sum + abs(v[n-1]-v[0]);
    
    return sum;
}