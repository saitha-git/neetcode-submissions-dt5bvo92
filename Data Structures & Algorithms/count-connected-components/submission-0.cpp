class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) 
    {
        visited[node] = true;
        for(auto nbr : adj[node])
        {
            if(!visited[nbr])
            {
                dfs(nbr, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());

        vector<bool> visited(n, false);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }
};
