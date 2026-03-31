class Solution {
public:
    const vector<string> digitToChar = {"", "", "abc", "def", "ghi",
                                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void solve(int start, string& digits, string& ans)
    {
            if(digits.size() == ans.size())
            {
                res.push_back(ans);
                return;
            }
            for(auto c : digitToChar[ digits[start] - '0' ])
            {
                ans += c;
                solve(start+1, digits, ans);
                ans.pop_back();
            }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return {};
        }

        string ans="";
        solve(0, digits, ans);

        return res;
    }
};
