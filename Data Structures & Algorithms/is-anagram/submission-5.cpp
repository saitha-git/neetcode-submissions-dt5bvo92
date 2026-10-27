class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
    
        for(char c : s) {
            freq[c]++;
        }

        for(char c : t){
            auto it = freq.find(c);
            
            if(it == freq.end()){
                return false;
            }
            
            if(--it->second == 0){
                freq.erase(it);
            }
        }

        return freq.empty();
    }
};
