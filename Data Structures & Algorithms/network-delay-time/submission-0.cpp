class Solution {
public:
    typedef pair<int, int> PII;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>> adj(n+1);
        for(const auto& time : times)
        {
            adj[time[0]].emplace_back(time[2], time[1]);
        }
        priority_queue<PII, vector<PII>, greater<>> minHeap;

        vector<int> visited(n+1, false);

        // dist, node
        minHeap.push({0,k});
        int w1;
        int t = 0;
        while(!minHeap.empty())
        {
            PII top = minHeap.top();
            minHeap.pop();
            int n1 = top.second; 
            w1 = top.first;
            
            if(visited[n1])
            {
                continue;
            }
            t = w1;

            visited[n1] = true;
            cout << "n1: "<< n1 << "size: "<<adj[n1].size() << endl;
            
            for(auto nbr : adj[n1])
            {
                
                int n2 = nbr.second; 
                int w2 = nbr.first;
                cout << "n2:" << n2 << "w2:" << w2 << endl;
                if(!visited[n2])
                {
                  minHeap.push({w1+w2,n2});
                }
                
            }
        }

        cout << visited.size() << endl;
        return count(visited.begin(), visited.end(), 1) == n ? t : -1;
    }
};


