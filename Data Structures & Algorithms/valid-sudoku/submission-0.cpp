class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> squares;  
        
        cout << board.size() << board[0].size() << endl;

        for(int r=0; r < board.size(); ++r)
        {
            for(int c=0; c < board[0].size(); ++c)
            {
               char cell = board[r][c];
               int k = 3*(r/3) + (c/3);

               if ( cell == '.' )
               {
                    continue;
               }

               if( rows[r].count(cell) || cols[c].count(cell) || squares[k].count(cell))
               {
                    return false;
               }
               else
               {
                    rows[r].insert(cell);
                    cols[c].insert(cell);
                    squares[k].insert(cell);
               }
            }
        }

        return true;
    }
};
