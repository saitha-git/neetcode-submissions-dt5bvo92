class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stack;
        vector<int> ans;

        for (int i=temperatures.size()-1; i>=0; --i)
        {
            
            while (!stack.empty() && stack.top().first <= temperatures[i])
            {
                stack.pop();
            }
        
            if(stack.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(stack.top().second - i);
            }
            stack.push({temperatures[i],i});
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

