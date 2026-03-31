class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;

        for(auto& task: tasks)
        {
            count[task]++;
        }
        
        priority_queue<int, vector<int>> maxHeap;
        for(auto& task: count)
        {
            maxHeap.push(task.second);
        }     

        int time = 0;
        queue<pair<int,int>> q; // {cnt,IdleCnt}
        while (!maxHeap.empty() || !q.empty())
        {
            if (!maxHeap.empty())
            {
                int top = maxHeap.top();
                if (top-1 != 0)
                {
                    q.push({top-1,time+n+1});
                }
                maxHeap.pop();
            }

            if (!q.empty())
            {
                pair<int,int> front = q.front();
                if (front.second-1 == time)
                {
                    q.pop();
                    maxHeap.push(front.first);
                }
            }

            time++;
        }

        return time;
    }
};


