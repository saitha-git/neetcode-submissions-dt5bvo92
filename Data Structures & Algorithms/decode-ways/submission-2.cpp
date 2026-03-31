class Solution {
public:
    vector<int> mem;

    int rec(int startIdx, string s) {
        if (s[startIdx] == '0') {
            return 0;
        }

        if (startIdx >= s.length()-1) {
            return 1;
        }

        if (mem[startIdx] != -1) {
            cout << mem[startIdx] << endl;
            return mem[startIdx];
        }
        
        if(startIdx+1 < s.length() && s[startIdx+1] != 0) {
            if(stoi(s.substr(startIdx, 2)) <= 26) {
                return mem[startIdx] = rec(startIdx+1, s) + rec(startIdx+2, s);
            } else {
                return mem[startIdx] = rec(startIdx+1, s);
            }
        }
        else  {
            return mem[startIdx] = rec(startIdx+2, s);
        }    
    }
    int numDecodings(string s) {
        mem.resize(s.length(), -1);
        return rec(0, s);
    }
};
