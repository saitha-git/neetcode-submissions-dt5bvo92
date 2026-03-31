class Solution {
private:
    struct TrieNode
    {
        bool        wordEnd;
        TrieNode*   child[26];

        TrieNode()
        {
            wordEnd = false;

            for(int i=0; i<26; i++)
            {
                child[i] = nullptr;
            }
        }
    }; 

    TrieNode* root;

    void addWords(const vector<string>& words)
    {

        for(const auto& word: words)
        {
            TrieNode* node = root;

            int index;
            for(const auto& c: word)
            {
                index = c - 'a';

                if (!node->child[index])
                {
                    node->child[index] = new TrieNode(); 
                }

                node = node->child[index];
            }
            node->wordEnd = true;
            cout << index << endl;
        }
    }

    //for j,j-1,j+1 (i,j), (i-1,j), (i+1,j)
    void dfs(   int row, int col,TrieNode* node, vector<vector<bool>> marked,
                string word,bool& found, vector<vector<char>>& board, unordered_set<string>& res)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || marked[row][col]) {
            return;
        }
        
        if (!marked[row][col])
        {
            int index = board[row][col] - 'a';
            //cout << board[row][col] << endl;
            if (node->child[index])
            {
                marked[row][col] = true;
                word = word+board[row][col];

                cout << word << endl;
                
                if (node->child[index]->wordEnd)
                {
                    found = true;
                    res.insert(word);
                }

                dfs(row, col+1, node->child[index], marked, word, found, board,res);
                dfs(row, col-1, node->child[index], marked, word, found, board,res);
                dfs(row-1, col, node->child[index], marked, word, found, board,res);
                dfs(row+1, col, node->child[index], marked, word, found, board,res);                   
            }
        }         
    }

public:
    Solution()
    {
        root = new TrieNode();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        addWords(words);
        int ROWS = board.size();
        int COLS = board[0].size();
        vector<bool> row(COLS, false);
        vector<vector<bool>> marked(ROWS,row);

        unordered_set<string> res;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                bool found = false;
                string word = "";
                
                dfs(r, c, root, marked, word, found, board,res);
                if (found)
                {
                    cout << word << endl;
                }
            }
        }

        vector<string> vec(res.begin(), res.end());
        return vec;
    }
};
