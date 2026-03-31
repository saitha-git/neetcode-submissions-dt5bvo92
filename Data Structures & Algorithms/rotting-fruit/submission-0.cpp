class Solution {
public:
    const vector<vector<int>> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    
    int bfs(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;
        for(int r=0; r<ROWS; r++)
        {
            for(int c=0; c<COLS; c++)
            {
                if (grid[r][c] == 2)
                {
                    q.push({r,c});
                    visited[r][c] = true;
                }
            }
        }

        int minutes = 0;
        while(!q.empty())
        {
            int size = q.size();
            bool rotted = false;
            for(int j=0; j<size; j++)
            {
                auto front = q.front();
                q.pop();

                for(int i=0; i<4; i++)
                {
                    int nr = front.first  + dir[i][0];
                    int nc = front.second + dir[i][1];

                    if( nr>=0 && nr<ROWS && nc>=0 && nc<COLS && grid[nr][nc] != 0 
                        && grid[nr][nc] == 1 && !visited[nr][nc])
                    {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        visited[nr][nc] = true;
                        rotted = true;
                    }
                }
            }
            if (rotted) {
                minutes++;
            }
        }

        return minutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int ans = bfs(grid);

        for(int r=0; r<ROWS; r++)
        {
            for(int c=0; c<COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                   return -1;
                }
            }
        }

        return ans;
    }
};
