class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxF = 0;
        int n = s.size();

        int i = 0;
        int j = 0;
        int maxW = 0;
        for(int j=0; j<n; j++)
        {
            count[s[j]]++;
            maxF = max(maxF, count[s[j]]);
            // number of replacements = j-i-maxF
            while((j-i+1)-maxF > k)
            {
                count[s[i]]--;
                i++;
            }
            maxW = max(maxW, j-i+1);
        }

        return maxW;

    }
};
