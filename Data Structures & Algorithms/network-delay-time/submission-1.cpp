class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Floyd Warshall Algo
        
        int inf = INT_MAX/2;
        vector<vector<int>> dp(n+1,vector<int>(n+1, inf));

        n = n+1;

        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        for(auto time : times)
        {
            int u = time[0];
            int v = time[1];

            dp[u][v] = time[2];
        }

        for(int mid=1; mid<n; mid++)
        {
            for(int i=1; i<n; i++)
            {
                for(int j=1; j<n; j++)
                {
                    dp[i][j] = min(dp[i][j], 
                                   dp[i][mid]+dp[mid][j]);
                }
            }
        }

        for(int i=1; i<n; i++)
        {
            cout << dp[k][i] << " ";
        }
        cout << endl;
        int res = *max_element(dp[k].begin()+1, dp[k].end());

        
        return res == inf ? -1 : res;
    }
};
