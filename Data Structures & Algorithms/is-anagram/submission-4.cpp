class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
    
        int i = 0;
        while(s[i]){
            map[s[i]]++;
            i++;
        }

        i = 0;
        while(t[i]){
            if(map.find(t[i]) == map.end()){
                return false;
            }
            map[t[i]]--;
            if(map[t[i]] == 0){
                map.erase(t[i]);
            }

            i++;
        }

        return map.empty();
    }
};
