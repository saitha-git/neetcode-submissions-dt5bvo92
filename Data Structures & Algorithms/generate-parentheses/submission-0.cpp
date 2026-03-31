class Solution {
public:
    vector<string> ans;

    void _generateParenthesis(int n,string parStr,int openCnt,int closedCnt) {
        if( parStr.length() == 2*n)
        {
            cout <<"ans:"<<"n:" << n << "parStr:" << parStr << "openCnt:" << openCnt << endl;
            ans.push_back(parStr);
            return;
        }
        cout << "n:" << n << "parStr:" << parStr << "openCnt:" << openCnt << endl;
        if (n-openCnt > 0)
            _generateParenthesis(n, parStr+"(", openCnt+1,closedCnt);
        
        if(openCnt && openCnt > closedCnt)
        {
            _generateParenthesis(n, parStr+")", openCnt,closedCnt+1);
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        
        _generateParenthesis(n,"",0,0);

        return ans;
    }
};
