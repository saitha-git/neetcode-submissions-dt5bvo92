class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsrVec;
        vector<int> nslVec;
        nsrVec = nsr(heights);
        nslVec = nsl(heights);

        int n = heights.size();
        for(int i=0; i<n; ++i)
        {
            cout<<nsrVec[i]<<":"<<heights[nsrVec[i]]<<" ";
        }
        cout<<endl;   
        for(int i=0; i<n; ++i)
        {
            cout<<nslVec[i]<<":"<<heights[nslVec[i]]<<" ";
        }
        cout<<endl;

        int maxH = INT_MIN;
        for(int i=0; i<n; ++i)
        {
            maxH = max(maxH, heights[i]*(nsrVec[i]-nslVec[i]-1));
        }
        
        return maxH;
    }

private:
    vector<int> nsr(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> stack;

        vector<int> ans(n,n);

        for(int i=0; i<n; ++i)
        {
            while (!stack.empty() && heights[stack.top()] > heights[i])
            {
                ans[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
    
        return ans;
    }

    vector<int> nsl(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> stack;

        vector<int> ans(n,-1);

        for(int i=0; i<n; ++i)
        {
            while (!stack.empty() &&  heights[stack.top()] >= heights[i] )
            {
                stack.pop();
            }
            
            if(!stack.empty())
            {
                ans[i] = stack.top();
            }

            stack.push(i);
        }

        return ans;
    }
};

