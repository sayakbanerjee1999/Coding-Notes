#include<bits/stdc++.h>
#define int long long int
using namespace std;
 

int32_t main(){
	int n;
    cin>>n;
    
    while(true){
        int arr[n];
        
        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        }
        
        vector<pair<int, int>> buy;
        vector<pair<int, int>> sell;
        
        for(int i = 0; i < n; i++){
        	if(arr[i] > 0)
        		buy.push_back({arr[i], i});
        	else
        		sell.push_back({arr[i], i});
        }
        
        int i = 0, j = 0, ans = 0;
        
        while(i < buy.size()  &&  j < sell.size()){
        	int x = min(buy[i].first, -1*(sell[j].first));
        	
        	buy[i].first -= x;
        	sell[j].first += x;
        	
        	int diff = abs(buy[i].second - sell[j].second);
        	
        	ans += (x*diff);
        	
        	if(buy[i].first == 0)
        		i++;
        	
        	if(sell[j].first == 0)
        		j++;
        }
        
        cout << ans << endl;
        
        cin >> n;
        if(n==0)
        	break;
    }
    
	return 0;
}