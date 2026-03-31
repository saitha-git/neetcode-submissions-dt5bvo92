class Solution {
public:

    int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<int>>& visited)
    {   
        if (grid[r][c] == '1' && visited[r][c] == 0)
        {
            visited[r][c] = 1;
            for(int i=0; i<4; ++i)
            {
                if (   ( r+direction[i][0]>=0 && r+direction[i][0] < grid.size() )   
                    && ( c+direction[i][1]>=0 && c+direction[i][1] < grid[0].size() ) )
                {  
                    dfs(grid, r+direction[i][0], c+direction[i][1], visited);
                }
            }
        }
        
    }
 
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(rows, vector<int>(cols,0));

        // i+/-1 j+/-1
        for(int r=0; r<grid.size(); ++r)
        {
            for(int c=0; c<grid[0].size(); ++c)
            {
                if ( (grid[r][c] == '1') && (visited[r][c] == 0) )
                {
                    count++;
                    cout << "grid:" << grid[r][c] << endl;
                    dfs(grid, r, c, visited);
                }
            }
        } 

        return count;
    }
};
