class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length())
        {
            return false;
        }

        bool isAnagram = true;
        unordered_map<char,int> hashmap;
        for (auto i=0; i<s.length(); ++i)
        {
            if (hashmap.find(s[i]) != hashmap.end())
            {
                ++hashmap[s[i]];
            }
            else
                hashmap[s[i]]=1;
        }

        #if 0
        for ( auto key : hashmap)
        {
            cout << key.first << ":" << key.second << endl;
        }
        #endif

        for (auto i=0; i<t.length(); ++i)
        {
            if ( hashmap.find(t[i]) != hashmap.end() )
            {
                hashmap[t[i]]--;
                if (hashmap[t[i]] == 0)
                {
                    hashmap.erase(t[i]);
                    cout << t[i] << endl;
                }
            }
            else
            {
                break;
            }
        }

        #if 0
        for ( auto key : hashmap)
        {
            cout << key.first << ":" << key.second << endl;
        }
        #endif

        return hashmap.empty();
    }
};
