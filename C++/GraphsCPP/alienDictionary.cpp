Alien Dictionary - GFG

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        vector<int> inDegree(K, 0);
        
        for(int i = 0; i < N-1; i++){
            string w1 = dict[i];
            string w2 = dict[i+1];
            
            for(int j = 0; j < min(w1.length(), w2.length()); j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    inDegree[w2[j]-'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < K; i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        
        string res = ""; 
        while(!q.empty()){
            int temp = q.front();
            char chr = temp+'a';
            q.pop();
            res += chr;
            
            for(auto x: adj[temp]){
                inDegree[x]--;
                if(inDegree[x]==0)
                    q.push(x);
            }
        }
        
        return res;
    }
};
