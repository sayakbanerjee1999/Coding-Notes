class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> hashmap;
        int prefixSum = 0;
        hashmap[prefixSum] = -1;
        int res = 0;

        for(int i = 0; i < A.size(); i++){
            prefixSum += A[i];
            
            // Sum Not Found Add to hashmap
            if(hashmap.find(prefixSum) == hashmap.end()){
                hashmap[prefixSum] = i;
            }
            
            // If sum found earlier find out length and update max
            else{
                int length = i - hashmap[prefixSum];
                res = max(res, length);
            }
        }
        
        return res;
    }
};
