class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap(stones.begin(), stones.end());
        
        while (!maxHeap.empty() && (maxHeap.size() > 1) )
        {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if (x == y)
            {
                
            }
            else if (x < y)
            {
                maxHeap.push(y-x);
            }

        }
              
        if (!maxHeap.empty())
            return maxHeap.top();
        else
            return 0;
    }
};




