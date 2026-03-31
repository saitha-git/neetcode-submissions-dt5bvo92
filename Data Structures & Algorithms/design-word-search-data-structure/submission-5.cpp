class WordDictionary {
    struct TrieNode
    {
        bool        wordEnd;
        TrieNode*   child[26];
        int         refs;
        
        TrieNode()
        {
            wordEnd = false;
            refs    = 0;

            for (int i=0; i<26; ++i)
            {
                child[i] = nullptr;
            }
        }
    };
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        
        for(const auto& c: word)
        {
            int index = c - 'a';
            if (nullptr == node->child[index])
            {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
            node->refs++;
        }
        node->wordEnd = true;
    }
    
    bool dfs(int index, int len, TrieNode* node, string& word)
    {  
        bool res = false;

        if ( index == len)
        {
            cout << "node->wordEnd:" <<  node->wordEnd << "index:" << index << endl;
            return res = node->wordEnd;
        }

        cout << "word:"<<word<<" word["<<index<<"]:" << word[index] << endl;
        if (word[index] == '.')
        {
            for (int i=0; i<26; ++i)
            {
                if (node->child[i])
                {
                    cout << "i:" << i << " len:" << len << " node->child[i]:" << node->child[i] << endl;
                    if (!res)
                        res = res || dfs(index+1, len, node->child[i], word);
                }   
            }
            return res;
        }
        else
        {
            if (node->child[word[index]-'a'])
            {
                if (!res)
                    res  = res || dfs(index+1, len, node->child[word[index] - 'a'], word);
                return res;
            }
            else {
                return res = false;
            }
        }

    }

    bool search(string word) {
        return dfs(0, word.length(), root, word);
    }
};
