class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        int n = points.size();

        vector<vector<vector<int>>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        vector<bool> visited(n, false);
        int nodeCount = 0;
        int cost = 0;

        minHeap.push({0,0});
        while(nodeCount < n && !minHeap.empty()) {
            auto top = minHeap.top();
            auto node = top[1];
            minHeap.pop();
            if(visited[node])
            {
                continue;
            }
            
            cost += top[0];
            visited[node] = true; 
            nodeCount++;
            
            for(auto& nbr : adj[node]) {
                int w = nbr[0];
                if(!visited[nbr[1]]) {
                    minHeap.push({w, nbr[1]});
                }
            }
        }

        return cost;
    }
};
