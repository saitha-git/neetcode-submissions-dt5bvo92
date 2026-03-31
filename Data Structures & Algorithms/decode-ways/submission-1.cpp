class Solution {
public:
    int rec(int startIdx, string s) {
        if (s[startIdx] == '0') {
            return 0;
        }
        
        if (startIdx >= s.length()-1) {
            return 1;
        }


        if(startIdx+1 < s.length() && s[startIdx+1] != 0) {
            if(stoi(s.substr(startIdx, 2)) <= 26) {
                return rec(startIdx+1, s) + rec(startIdx+2, s);
            } else {
                return rec(startIdx+1, s);
            }
        }
        else  {
            return rec(startIdx+2, s);
        }    
    }
    int numDecodings(string s) {
        return rec(0, s);
    }
};
