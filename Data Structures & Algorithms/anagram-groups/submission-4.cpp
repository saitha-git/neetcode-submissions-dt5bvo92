class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> hashmap;

        for(auto& s: strs)
        {
            vector<int> count(26,0);
            for(auto& c: s)
            {
                count[c-'a']++;
            }

            string key="";
            for(auto& i: count)
            {
                cout << i << " " <<to_string(i) << endl;
                key += "#"+to_string(i);
            }
            cout << key << endl;

            hashmap[key].push_back(s);
        }

        vector<vector<string>> ans;
        for( auto& pair: hashmap)
        {
            ans.push_back(pair.second);
        }
        
        return ans;
    }
};
