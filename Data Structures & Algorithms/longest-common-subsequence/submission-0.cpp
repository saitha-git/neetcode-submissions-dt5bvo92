class Solution {
public:
    vector<vector<int>> dp;

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        dp.resize(n2+1, vector<int>(n1+1, 0));

        for (int r=1; r<=n2; r++) {
            for (int c=1; c<=n1; c++) {
                if(text2[r-1] == text1[c-1]) {
                    dp[r][c] = 1+ dp[r-1][c-1];
                }
                else {
                    dp[r][c] = max(dp[r][c-1], dp[r-1][c]);
                }
            }
        }

        return dp[n2][n1];
    }
};
