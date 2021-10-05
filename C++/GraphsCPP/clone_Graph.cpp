class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        
        queue<Node*> q;
        q.push(node);        
        vector<Node*> res(101, NULL);

        res[node->val] = new Node(node->val);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto current = q.front();
                q.pop();
                
                for(auto next: current->neighbors){
                    if(!res[next->val]){
                        res[next->val] = new Node(next->val);
                        q.push(next);
                    }
                    
                    res[current->val]->neighbors.push_back(res[next->val]);
                }
            }
        }
        return res[node->val];
    }
};
