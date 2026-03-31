class Solution {
public:
    vector<vector<bool>> visited;
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i)
    {
        if ( i == word.size())
        {
            return true;
        }
        
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()
           || board[r][c] != word[i] || visited[r][c] )
        {
            return false;
        }

        visited[r][c] = true;
        bool res =     dfs(board, word, r-1, c, i+1)
                    || dfs(board, word, r+1, c, i+1)
                    || dfs(board, word, r, c-1, i+1)
                    || dfs(board, word, r, c+1, i+1) ;
        visited[r][c] = false;
        
        return res;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int r=0; r<rows; r++)
        {
            for(int c=0; c<cols; c++)
            {
                if(dfs(board, word, r, c, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
