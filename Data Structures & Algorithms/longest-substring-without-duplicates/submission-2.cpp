class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = l+1;
        unordered_set<char> set;
        int ans = 1;

        if(0 == s.size())
            return 0;

        set.insert(s[l]);
        while( r < s.size())
        {
            while (l<=r && set.find(s[r])!=set.end())
            {
                set.erase(s[l]);
                l++;
            }
            
            set.insert(s[r]);
            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};



