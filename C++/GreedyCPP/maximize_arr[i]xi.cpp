int mod = 1000000007;
int Maximize(int arr[],int n)
{
    // Complete the function
    sort(arr, arr+n);
    
    long long int ans = 0;
    
    for(int i = 0; i < n; i++){
        ans = (ans + ((long long int)arr[i]*i)%mod )%mod;;
    }
    
    return ans%mod;
}