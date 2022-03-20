class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        //Your code here
        sort(arr, arr + N);
        
        // Remove duplicates
        vector<int> res;
        res.push_back(arr[0]);
        for(int i = 1; i < N; i++){
            if(arr[i] != arr[i-1])
                res.push_back(arr[i]);
            else
                continue;
        }
        
        int count = 0, ans = 0;
        for(int i = 0; i < res.size(); i++){
            if(i > 0  && res[i] - res[i-1] == 1){
                count++;
            }
            
            else{
                count = 1;
            }
            
            ans = max(count, ans);
        }
        
        return ans;
    }
};
