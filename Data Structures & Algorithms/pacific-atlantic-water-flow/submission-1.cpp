class Solution {
public:
    const vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1},
    {0,-1}};
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights)
    {
        ocean[r][c] = true;
        int ROWS = heights.size();
        int COLS = heights[0].size();
        for(const auto& dir : directions)
        {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if(   nr>=0 && nr<ROWS 
               && nc>=0 && nc<COLS
               && !ocean[nr][nc]
               && heights[nr][nc]>=heights[r][c])
            {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
    
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        
        for(int r=0; r<ROWS; r++)
        {
            dfs(r,0, pac, heights);
            dfs(r,COLS-1, atl, heights);
        }

        for(int c=0; c<COLS; c++)
        {
            dfs(0, c, pac, heights);
            dfs(ROWS-1, c, atl, heights);
        }

        vector<vector<int>> ans;
        for(int r=0; r<ROWS; r++)
        {
            for(int c=0; c<COLS; c++)
            {
                if(pac[r][c] && atl[r][c])
                {
                    ans.push_back({r,c});
                }
            }
        }

        return ans;
    }        

};
