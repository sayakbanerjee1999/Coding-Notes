static bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second==b.second)
        return a.first<b.first;
    
    return a.second<b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++)
        v[i] = {start[i], end[i]};
    
    sort(v.begin(), v.end(), cmp);
    
    int i = 0, j = 1;
    int countMeetings=1;
    
    while(j < n){
        if(v[i].second < v[j].first){
            i = j;
            j++;
            countMeetings++;
        }
        
        else
            j++;
    }
    
    return countMeetings;
}