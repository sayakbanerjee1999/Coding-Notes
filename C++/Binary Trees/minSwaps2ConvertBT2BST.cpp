Remember InOrder Traversal of BST always gives a sorted array
So question simply changes to -> Converting unsorted array to sorted array using minimum number of swaps

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int size = nums.size();
	    
	    vector<pair<int, int>> arr;
	    for(int i = 0; i < size; i++){
	        arr.push_back({nums[i], i});
	    }
	    
	    sort(arr.begin(), arr.end());
	    
	    int countSwaps = 0;
	    for(int i = 0; i < size; i++){
	        if(i == arr[i].second)
	            continue;
	        
	        else{
	            swap(arr[i], arr[arr[i].second]);
	            countSwaps++;
	            i--;    // Recheck if newly swapped element is in correct position
	        }
	    }
	    
	    return countSwaps;
	}
};
