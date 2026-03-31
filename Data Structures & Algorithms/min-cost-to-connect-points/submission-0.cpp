class DSU
{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }
    }

    bool _union(int u, int v)
    {
        int pU = find(u);
        int pV = find(v);
        if (pU != pV)
        {
            if(rank[pU] < rank[pV])
            {
                parent[pU] = pV;
                rank[pV] += rank[pU];
            }
            else
            {
                parent[pV] = pU;
                rank[pU] += rank[pV];
            }
            return true;
        }

        return false;
    }

    int find(int u)
    {
        if ( u == parent[u])
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<int>> edges;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int dist =      abs(points[i][0]-points[j][0])
                           +    abs(points[i][1]-points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int edgeCnt = 0;
        int cost = 0;
        DSU insDsu = DSU(n);
        
        for(const auto edge : edges)
        {
            int u = edge[1];
            int v = edge[2];
            int w = edge[0];
            // to detect whether the edge will form a cycle
            if(insDsu.find(u) != insDsu.find(v))
            {
                insDsu._union(u,v);
                cost += w;
                edgeCnt++;
            }
            if(n-1 == edgeCnt)
                break;
        }

        return cost;
    }
};
