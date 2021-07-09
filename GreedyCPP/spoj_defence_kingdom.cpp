#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
		int w, h, n;
		cin >> w >> h >> n;
		
		vector<int> a;
		vector<int> b;
		
		a.push_back(0);
		b.push_back(0);
		
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			
			a.push_back(x);
			b.push_back(y);
		}
		
		a.push_back(w+1);
		b.push_back(h+1);
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		int max_x = 0;
		int max_y = 0;
		
		for(int i = 1; i < a.size(); i++){
			max_x = max(max_x, a[i] - a[i-1] - 1);
			max_y = max(max_y, b[i] - b[i-1] - 1);
		}
		
		cout << max_x*max_y << endl;
	}
	
	return 0;
}