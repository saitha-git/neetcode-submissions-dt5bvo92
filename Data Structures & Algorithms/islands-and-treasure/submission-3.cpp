
class Solution {
public:
    const int INF = 2147483647;
    typedef pair<int, int> PII; // Type alias using typedef
    const vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& grid,int r, int c, vector<vector<bool>>& visited)
    {     
        // invalid
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() 
           || grid[r][c] == -1 || visited[r][c])
            return INF;

        // Base condition
        if (grid[r][c] == 0)
            return 0;

        int res = INF;
        visited[r][c] = true;
        for(auto dir : directions)
        {
            int ans = dfs(grid, r+dir[0], c+dir[1], visited);
            if (ans!=INF)
                res = min(res, 1+ans);
        }
        visited[r][c] = false;
        
        return res;
    }

    
    int bfs(vector<vector<int>>& grid, int r, int c)
    {
        queue<PII> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        int steps = 0;

        q.push({r,c});
        visited[r][c] = true;
        while(!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                PII front = q.front();
                q.pop();
                r = front.first;
                c = front.second;

                if (grid[r][c] == 0)
                    return steps;

                for(auto dir : directions)
                {
                    int nr = front.first  + dir[0];
                    int nc = front.second + dir[1];

                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && 
                        !visited[nr][nc] && grid[nr][nc] != -1)
                    {
                        visited[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }
            steps++;
        }

        return INF;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for(int r=0; r<ROWS; r++)
        {
            for(int c=0; c<COLS; c++)
            {
                if(grid[r][c] == INF)
                    grid[r][c] = bfs(grid, r, c) ;
            }
        }

    }
};
