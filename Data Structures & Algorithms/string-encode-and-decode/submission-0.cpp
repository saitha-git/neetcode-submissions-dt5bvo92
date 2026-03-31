class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for(auto& str: strs)
        {
            result += to_string(str.size())+"#"+str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str;
        int i = 0;
        int len ;

        while( i< s.size() )
        {
            int j = i;
            while ( s[j] != '#')
            {
                j++;
            }
            len = stoi(s.substr(i, j - i));
            str = s.substr(j+1,len);
            ans.push_back(str);
            i = j+1+len;
        }

        return ans;
    }
};
