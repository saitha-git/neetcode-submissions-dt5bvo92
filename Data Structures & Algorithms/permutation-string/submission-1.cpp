class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSz = s1.length();
        
        if(s1.length() > s2.length())
        {
            return false;
        }

        unordered_map<char,int> map;
        int r = 0;
        int count = 0;
        while(r<windowSz)
        {
            if(map.find(s1[r]) == map.end())
            {
                ++count;
            }
            map[s1[r]]++;
            r++;
        }

        int l = 0;
        r = 0;
        while(r<s2.length())
        {
            if(map.find(s2[r]) != map.end())
            {
                map[s2[r]]--;
                if(map[s2[r]] == 0)
                {
                    count--;
                }
            }
            
            if(r < windowSz-1)
            {
                r++;
            }
            else if(r-l+1 == windowSz)
            {
                if(count == 0)
                {
                    return true;
                }
                r++;
                if(map.find(s2[l]) != map.end())
                {
                    if(map[s2[l]] == 0)
                    {
                        count++;
                    }
                    {
                        map[s2[l]]++;
                    }
                }
                l++;
            }
        }

        return false;
    }
};
