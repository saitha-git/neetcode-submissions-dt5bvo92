class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int count[strs.size()][26] = {};
        vector<vector<string>> ans;

        for(auto i=0;i<strs.size();++i)
        {
            for(auto c: strs[i])
            {
                count[i][c-'a'] += 1;
            }
        }

        auto itr=0;
        bool visited[strs.size()] = {};
        for(auto i=0;i<strs.size();++i)
        {
            if (visited[i] == false)
            {
                ans.push_back(vector<string>()); // Add a new group
                ans[itr].push_back(strs[i]);
                visited[i] = true;

                for(auto j=i+1;j<strs.size();++j)
                {
                    if (visited[j] == false)
                    {
                        if ( strs[i].length() == strs[j].length())
                        {
                            auto k =0;
                            for(; k<26; k++)
                            {
                                if(count[i][k]  != count[j][k] )
                                {
                                    break;
                                }
                            }

                            if (k == 26)
                            {
                                ans[itr].push_back(strs[j]);
                                visited[j] = true;
                            }
                        }
                    }
                }
                itr++;
            }
        }

        return ans;
    }
};
