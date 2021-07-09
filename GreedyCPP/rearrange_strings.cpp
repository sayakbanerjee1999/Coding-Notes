string reorganizeString(string S) {
    unordered_map<char, int> hashmap;
    
    for(int i = 0; i < S.length(); i++){
        if(hashmap.find(S[i]) == hashmap.end())        //Not found;
            hashmap[S[i]] = 1;
        else
            hashmap[S[i]]++;
    }
    
    // Make sure that the most frequent characters occur at the top
    priority_queue<pair<int, int>> maxH;
    for(auto it:hashmap)
        maxH.push({it.second, it.first});
    
    string res = "";
    while(maxH.size()>1){
        pair<int,int> most = maxH.top(); 
        maxH.pop();
        pair<int, int> less = maxH.top(); 
        maxH.pop();
        
        res += most.second;
        res += less.second;
        
        int freq_most = most.first - 1;
        int freq_less = less.first - 1;
        
        if(freq_most > 0)
            maxH.push({freq_most, most.second});
        
        if(freq_less > 0)
            maxH.push({freq_less, less.second});
    }
    
    if(!maxH.empty()){
        pair<int, int> top = maxH.top();
        maxH.pop();
        if(top.first > 1)
            return "";
        
        else
            res += top.second;
    }
    
    return res;
}