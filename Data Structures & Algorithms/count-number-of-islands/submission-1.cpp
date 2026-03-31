class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == '0' || visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        cout << "r:" << r << "c:" << c << endl;
        dfs(grid, visited, r+1, c);
        dfs(grid, visited, r-1, c);
        dfs(grid, visited, r, c+1);
        dfs(grid, visited, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int C = grid[0].size();
        int R = grid.size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int count = 0;
        for(int r=0; r<R; r++) {
            for( int c=0; c<C; c++) {
                if(!visited[r][c] && grid[r][c] == '1'){
                    count++;
                    dfs(grid, visited, r, c);
                }
            }
        }

        return count;
    }
};
