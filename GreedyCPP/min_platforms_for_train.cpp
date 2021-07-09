int findPlatform(int arr[], int dep[], int n){
	// Your code here
    sort(arr, arr+n);
    sort(dep, dep+n);
    
    int plat_req = 1;           //For first train
    int i = 1;
    int j = 0;
    
    while(i<n){
        if(arr[i]<=dep[j])
            plat_req++;
        else
            j++;        //Increase if arr[i]>dep[j] increment j and compare
        
        i++;            //Increase in each count
    }
    
    return plat_req;
}