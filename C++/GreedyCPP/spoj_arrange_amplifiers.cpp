#include <bits/stdc++.h>
#define int long long int 
using namespace std;

int32_t main() {
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int arr[n];
		int ones = 0;
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			
			if(arr[i]==1)
				ones++;
		}
			
		sort(arr, arr+n, greater<int>());
	
		for(int i = 0; i < ones; i++)
			cout << "1 ";
		
		if((n-ones)==2 && arr[0]==3 && arr[1]==2){
			cout << "2 3" << endl;
		}
		else {
			for(int i = 0; i < (n-ones); i++){
				cout << arr[i] << " ";
			}
			
			cout << endl;
		}
	}
	
	return 0;
}