class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int op2;
        int op1;

        for(auto token: tokens)
        {
            if ( (token == "+") || (token == "*") || (token == "-") || (token == "/") )
            {    
                op2 = stack.top();
                stack.pop();
                op1 = stack.top();
                stack.pop();

                if(token == "+")
                {
                    stack.push(op1+op2);
                }
                else if(token == "-")
                {
                    stack.push(op1-op2);
                }
                else if(token == "*")
                {
                    stack.push(op1*op2);    
                }
                else if(token == "/")
                {
                    stack.push(op1/op2);                    
                }

            }
            else
            {
                stack.push(stoi(token));
            }
        
        }

        return stack.top();
    }
};
