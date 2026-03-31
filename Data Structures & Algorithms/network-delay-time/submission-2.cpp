class Solution {
public:
    typedef pair<int, int> pII;
    vector<int> dist;

    void dfs(int node, vector<vector<pII>>& adj, vector<bool>& visited)
    {
        for(auto it : adj[node])
        {
            int nbr = it.first;
            int w   = it.second;
            if(!visited[nbr])
            {
                cout << "nbr: " << nbr << 
                " w+dist[node]" << w+dist[node] << endl;
                dist[nbr] = min(dist[nbr], w+dist[node]);
                visited[nbr] = true;
                cout << "dist[nbr]:" << dist[nbr] << endl;
                dfs(nbr, adj, visited);
                visited[nbr] = false;
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pII>> adj(n+1);
        dist.assign(n+1, INT_MAX);

        for(const auto& time : times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v,w});
        }

        
        vector<bool> visited(n+1, false);
        visited[k] = true;
        dist[k] = 0;
        dfs(k, adj, visited);

        int ret = *max_element(dist.begin()+1, dist.end());

        return ret == INT_MAX ? -1 : ret;
    }
};
