class Solution {
public:
    int solve(string word1, int word1Idx, string word2, int word2Idx) {
        if(word2Idx == word2.size()) {
            return word1.size() - word1Idx;
        }
        if(word1Idx == word1.size()) {
            return word2.size() - word2Idx;
        }

        if (word1[word1Idx] == word2[word2Idx]) {
            return solve(word1, word1Idx+1, word2, word2Idx+1);
        } else {
            //replace
            int x = 1 + solve(word1, word1Idx+1, word2, word2Idx+1);
            //insert
            int y = 1 + solve(word1, word1Idx, word2, word2Idx+1);
            //delete
            int z = 1 + solve(word1, word1Idx+1, word2, word2Idx);

            return min(x, min(y,z));
        }
    }
    int minDistance(string word1, string word2) {
        return solve(word1, 0, word2, 0);
    }
};
