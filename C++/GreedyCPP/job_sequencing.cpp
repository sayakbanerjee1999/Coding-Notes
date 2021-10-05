struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

static bool compare(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) { 
    // your code here
    sort(arr, arr+n, compare);
    
    vector<bool> slot(n, false);
    
    int jobsDone = 0, profit = 0;
    for(int i = 0; i < n; i++){
        for(int j = min(n, arr[i].dead - 1); j>=0; j--){        // min function added to avoid segmentation fault and -1 for 0 based indexing
            if(!slot[j]){
                jobsDone ++;
                profit += arr[i].profit;
                
                slot[j] = true;
                
                break;                                          // Break once done
            }
        }
    }
    
    return {jobsDone, profit};
}