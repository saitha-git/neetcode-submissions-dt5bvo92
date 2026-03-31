class Solution {
public:
    void bfs(vector<vector<char>>& grid,int r, int c) {
        queue<pair<int, int>> q;
        grid[r][c] = '0';
        q.push({r,c});

        vector<vector<int>> dir = {{1,0},{-1,0}, {0,1}, {0,-1}};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int r1 = r+dir[i][0];
                int c1 = c+dir[i][1];
                if(  r1<0 || r1>=grid.size()
                   || c1<0 || c1>=grid[0].size()) {
                    continue;
                }
                if(grid[r1][c1] == '1') {
                    grid[r1][c1] = '0';
                    q.push({r1,c1});
                }
            }
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int count = 0;
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                if(grid[r][c] == '1') {
                    count++;
                    bfs(grid, r, c);
                }
            }
        }
        return count;
    }
};
