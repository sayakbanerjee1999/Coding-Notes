class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        queue<string> q;
        q.push(start);
        int wordSize = start.length();
        
        unordered_set<string> word;
        for(int i = 0; i < wordList.size(); i++)
            word.insert(wordList[i]);
        
        if(word.find(end)==word.end())      //EndWord not fount in set
            return 0;
        
        int count = 0;
        while(!q.empty()){
            count++;
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                string s = q.front();
                q.pop();
                
                for(int j = 0; j < wordSize; j++){
                    char org = s[j];
                    
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        s[j] = ch;
                        
                        if(s==end)
                            return count+1;
                        if(word.find(s)==word.end())        //Not Found
                            continue;
                        
                        //Else its found
                        word.erase(s);
                        q.push(s);
                    }
                    
                    s[j] = org;
                }
            }
        }
        
        return 0;
    }
};
