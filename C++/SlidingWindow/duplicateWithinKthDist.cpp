class Solution{
public:
	bool checkDuplicatesWithinK(int arr[], int n, int k) {
	    // code here
	    bool flag = false;
	    unordered_map<int, int> hash;
	    int i = 0, j = 0;
	    
	    while(j < n){
	        if(hash.find(arr[j]) == hash.end())
	            hash[arr[j]] = 1;
	        else
	            hash[arr[j]]++;
	            
	        if(j-i+1 < k){
	            j++;
	        }
	        
	        else if(j-i+1 == k){
	            if(hash.size() < k){
	                flag = true;
	                break;
	            }
	            
	            if(hash.find(arr[i]) != hash.end()){
	                hash[arr[i]]--;
	                
	                if(hash[arr[i]] == 0)
	                    hash.erase(arr[i]);
	            }
	            
	            i++; j++;
	        }
	    }
	    
	    return flag;
	}
};
