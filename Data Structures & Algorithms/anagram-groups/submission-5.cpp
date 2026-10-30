class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res; 
        for (auto s : strs) {
            array<int, 26> count{};
            for(auto c : s) {
                count[c-'a']++; 
            }

            string key;
            for(int i=0; i<26; i++) {
                key += ','+ to_string(count[i]);
            }
            // cout << key << " " << s << endl;
            res[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto val : res) {
            ans.push_back(val.second);
        }
        return ans;
    }
};
