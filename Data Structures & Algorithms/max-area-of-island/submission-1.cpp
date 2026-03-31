class Solution {
public:
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& visited)
    {
        int r1,c1;
        int count = 1;

        for(int i=0; i<4; ++i)
        { 
            r1 = r+dir[i][0];
            c1 = c+dir[i][1];
            if(   r1 >= 0 && r1 < grid.size()
               && c1 >= 0 && c1 < grid[0].size())
            {
                if (grid[r1][c1] && !visited[r1][c1])
                {
                    visited[r1][c1] = 1;
                    count += dfs(grid, r1, c1, visited);
                }
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        vector<vector<int>> visited(rows, vector<int>(cols,0));
        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if (grid[r][c] && !visited[r][c])
                {
                    cout << "Main:" << "r:" << r << "c:" << c << endl;
                    visited[r][c] = 1;
                    maxArea = max(maxArea, dfs(grid, r, c, visited));
                }
            }
        }

        return maxArea;
    }
};
