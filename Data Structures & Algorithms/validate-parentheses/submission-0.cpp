class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for(const auto& c: s) 
        {
            if ('(' == c or '{' == c or '[' == c)
            {
                cout << c << endl;
                stack.push(c);
            }
            else
            {
                char open;

                if (')' == c)
                {
                    open = '(';
                }
                else if ('}' == c)
                {
                    open = '{';
                }
                else if (']' == c)
                {
                    open = '[';
                }

                // cout << open << endl;
                if(!stack.empty() && stack.top() == open)
                {
                    cout << open << endl;
                    stack.pop();
                }
                else
                    return false;
            }
        }

        if(!stack.empty())
            return false;
        else
            return true;
    }
};
