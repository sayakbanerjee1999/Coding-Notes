int catchThieves(char arr[], int n, int k) {
    // Code here 
    vector<int> police;
    vector<int> thief;
    
    for(int i = 0; i < n; i++){
        if(arr[i]=='P')
            police.push_back(i);
        else if(arr[i]=='T')
            thief.push_back(i);
    }
    
    int i = 0; 
    int j = 0;
    
    int count = 0;
    
    while(i<police.size() && j<thief.size()){
        if(abs(police[i] - thief[j]) <= k){
            i++;
            j++;
            count++;
        }
        
        // Increment j if thief index less
        else if(thief[j]<police[i])
            j++;
        
        else
            i++;
    }
    
    return count;
}