class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> charMap;
        int minWin = INT_MAX;
        string ans;
        int count = 0;
        for(int i=0; i<t.size(); ++i)
        {
            charMap[t[i]]++;
        }
        count = t.size();
        //cout << "count:" << count << endl;

        int l = 0;
        int r = 0;
        while (charMap.find(s[l]) == charMap.end())
        {
            l++;
        }
        // cout << "l:" << l << endl;

        r = l;
        while( r < s.size())
        {
            if (charMap.find(s[r]) != charMap.end())
            {
                if( charMap[s[r]] > 0)
                    count--; 
                charMap[s[r]]--;
             
            }
                
            cout <<"s[r]:" <<s[r]<< "count1:" << count << endl;

            while ( count == 0 )
            {
                minWin = min(minWin,r-l+1);
                if (r-l+1 == minWin)
                {
                    ans = s.substr(l,minWin);
                    //cout << "count1:" << count << endl;
                    cout << ans << endl;
                }
                cout << "ans1:" << s.substr(l,r-l+1) << endl;

                if (charMap.find(s[l]) != charMap.end())
                {
                  
                        charMap[s[l]]++;
                        if( charMap[s[l]] > 0)
                            count++;
                        
                                        
                    cout <<"s[l]:" <<s[l]<< "count1:" << count << "l:"<<l<<" charcount:" << charMap[s[l]]<< endl;
                }
                l++;
            }

            r++;
        }

        return ans;
    }
};



