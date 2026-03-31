class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq, window;
        for(auto c : t) {
            freq[c]++;
        }

        int l = 0;
        int r = 0;

        int need = freq.size();
        int have = 0;

        while (freq.find(s[l]) == freq.end()) {
            l++;
            r++;
        }

        int minLen = INT_MAX;
        string ans="";

        while (r < s.size()) {
            
            if (freq.find(s[r]) != freq.end()) {
                window[s[r]]++;
                if (window[s[r]] == freq[s[r]] ) {
                    have++;
                }
            }

            while(have == need) {
                cout <<"l: " << l << " r:" << r << endl;

                if(r-l+1 < minLen ) {
                    minLen = r-l+1;
                    ans = s.substr(l, minLen);
                }
                
                if (freq.find(s[l]) != freq.end()) {
                    window[s[l]]--;
                
                    if (window[s[l]] < freq[s[l]] ) {
                        have--;
                    }
                }
                l++;
            }

            r++;
        }


        return ans;
    }
};
