class Solution {
public:
    int find_set(vector<int>& parent, int v)    
    {
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent, parent[v]);
    }

    bool union_set(vector<int>& parent, vector<int>& rank, int u, int v, int& num_components)
    {
        int u_set_id = find_set(parent, u);
        int v_set_id = find_set(parent, v);
        if (u_set_id != v_set_id)
        {
            num_components--;
            if(rank[u] < rank[v])
            {
                parent[u_set_id] = v_set_id;
                rank[v] += rank[u];
            }
            else
            {
                parent[v_set_id] = u_set_id;
                rank[u] += rank[v];
            }
            return false;
        }
        else
        {
            return true;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        n++;
        vector<int> parent;
        parent.resize(n);
        vector<int> rank(n, 1);

        for(auto v=0; v<n; v++)
        {
            parent[v] = v;
        }

        int num_components = n;

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            if(union_set(parent, rank, u, v, num_components))
                return vector<int>{u,v};
        }

        return {};
    }
};

