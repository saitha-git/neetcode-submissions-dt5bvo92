class Solution {
public:
    bool isPalindrome(string s) {
        int itr1 = 0;
        int itr2 = s.length() - 1;

        cout << itr2 << ":" << s[itr2] << endl;
        cout << itr1 << ":" << s[itr1] << endl;
       
        while( itr1 < itr2 )
        {
            while( (!isalnum(s[itr1])) && (itr1 < itr2) )
            {
                itr1++;
            }

            while( (!isalnum(s[itr2])) && (itr1 < itr2) )
            {
                cout << itr2 << ":" << s[itr2] << endl;
                itr2--;
            }
            
            if( tolower(s[itr1]) != tolower(s[itr2]) )
            {
                return false;
            }

            ++itr1;
            --itr2;
        }

        return true;

    }
};
