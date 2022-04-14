class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashmap;
        
        for(int i = 0; i < s.length(); i++){
            if(hashmap.find(s[i]) == hashmap.end())
                hashmap[s[i]] = 1;
            else
                hashmap[s[i]]++;
        }
        
        priority_queue<pair<int, char>> maxH;
        for(auto it: hashmap){
            maxH.push({it.second, it.first});
        }
        
        string res = "";
        while(!maxH.empty()){
            auto temp = maxH.top();
            maxH.pop();
            
            for(int i = 0; i < temp.first; i++){
                res += temp.second;
            }
        }
        
        return res;
    }
};


----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Using Hashmap and Compare Function
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    
    return a.first > b.first;
}

vector<int> freqSort(int *arr, int n){
    unordered_map<int, int> hashmap;
    
    for(int i = 0; i < n; i++){
        if(hashmap.find(arr[i]) == hashmap.end())
            hashmap[arr[i]] = 1;
        else
            hashmap[arr[i]]++;
    }
    
    vector<pair<int, int>> store;
    for(auto it: hashmap)
        store.push_back({it.second, it.first});
    
    sort(store.begin(), store.end(), compare);
    
    vector<int> res;
    for(int i = 0; i < store.size(); i++){
        for(int j = 0; j < store[i].first; j++){
            res.push_back(store[i].second);
        }
    }
    
    return res;
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	       
	    vector<int> ans = freqSort(arr, n);
	    
        for(int i = 0; i < n; i++)
	        cout << ans[i] << " ";
	    
	    cout << endl;
	}
	
	return 0;
}
