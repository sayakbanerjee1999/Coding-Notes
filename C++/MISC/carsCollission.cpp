// -ve followed by +ve cars will never collide as they move away
// +ve followed by -ve cars will collide as they are moving towards each other

#include <bits/stdc++.h>
using namespace std;

vector<int> carsCollission(int *arr, int n){
    stack<int> s;

    for(int i = 0; i < n ;i++){
        if(s.empty()){
            s.push(arr[i]);
        }
        else{
            // Positive Cars will always be pushed in the stack as negative cars move away
            // and positive cars move in the same direction so will never collide
            if(arr[i] > 0){
                s.push(arr[i]);
            }
            else{
                while(!s.empty()  &&  s.top() > 0  &&  s.top() < abs(arr[i])){
                    s.pop();
                }

                if(s.empty()){
                    s.push(arr[i]);
                }

                // Negative car present and hence can be pushed
                else if(s.top() < 0){
                    s.push(arr[i]);

                // Otherwise Car is destroyed;
                }
            }
        }
    }

    vector<int> res;

    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}


int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> res = carsCollission(arr, n);

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "   ";
    }

    return 0;
}


