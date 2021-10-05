#include<bits/stdc++.h>
#define int long long int
using namespace std;
 
int dp[1001][1001];
 
int solve(int h,int a,int i){
    if(h<=0 or a<=0)
        return 0;
        
    if(dp[h][a]!=-1)
        return dp[h][a];
    
    int x = 0, y = 0, z = 0;
    
    // If you are not in air; you can move to air
    if(i!=1)  
    	x = 1 + solve(h+3,a+2,1);
    // If you are not in water; you can move to water
    if(i!=2)  
    	y = 1 + solve(h-5,a-10,2);
    
    // If you are not in fire; you can move to fire
    if(i!=3)  
    	z = 1 + solve(h-20,a+5,3);
    
    dp[h][a] = max({x, y, z});
    
    return dp[h][a];
}
 
 
int32_t main() {
 
    int t;
    cin>>t;
    
    while(t--){
        int health,armor;
        cin>>health>>armor;
        
        dp[health+1][armor+1];
        memset(dp,-1,sizeof(dp));
        
        cout << max({solve(health+3,armor+2,1), solve(health-5,armor-10,2), solve(health-20,armor+5,3)}) << endl;
    }
 
    return 0;
}