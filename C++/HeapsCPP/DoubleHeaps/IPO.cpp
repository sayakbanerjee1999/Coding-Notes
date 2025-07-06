class Solution {

// 1. Maintain 2 heaps.
//     1. Profit Heap <int> which is a max array
//     2. Capital Heap <capital, profit(pair)> which is a min array.
//         1. Push all pairs in Capital
// 2. Loop k times:
//     1. While capital Heap is not empty and the top.first(capital) <= w(required capital)
//         1. Push the top.second to Profit Heap
//     2. If profitHeap empty -> break
//     3. w +‎ =  profitHeap.top(); profitHeap.pop()
  
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> profitH;            // Max Profit so maxH
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> capitalH;                                // Min Capital so minH

        for(int i = 0; i < profits.size(); i++){
            capitalH.push({capital[i], profits[i]});
        }

        for(int i = 0; i < k; i++){
            
            // Add all profits to the maxH if capital req <= w
            while(!capitalH.empty() && capitalH.top().first <= w){
                auto top = capitalH.top();
                capitalH.pop();
                profitH.push(top.second);
            }

            if(profitH.empty())
                break;

            // Take the maximum profit and add to the sum
            w += (profitH.top());
            profitH.pop();
        }

        return w;
    }
};
