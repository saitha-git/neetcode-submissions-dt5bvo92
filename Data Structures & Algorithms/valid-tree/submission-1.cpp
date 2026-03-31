class Solution {
public:
    vector<int> vertices;
    bool dfs(int node, vector<vector<int>>& adj, int parent, vector<bool>& visited)
    {
        visited[node] = true;
        vertices.push_back(node);
        for(auto nbr : adj[node])
        {
            if(!visited[nbr])
            {
                if (dfs(nbr, adj, node, visited))
                    return true;
            }
            else if (nbr != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n,false);
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if(dfs(0, adj, -1, visited))
            return false;

        return vertices.size() == n;
    }
};
