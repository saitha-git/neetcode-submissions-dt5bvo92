class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bot = matrix.size()-1;

        while(top < bot)
        {
            int mid = top+(bot-top)/2;

            if(target == matrix[mid][0])
            {
                return true;
            }
            else if(target < matrix[mid][0])
            {
                bot = mid-1; 
            }
            else
            {
                top = mid+1;
            }
        }

        cout <<"top:" << top <<"bottom:"<<bot<<endl;

        if(target < matrix[top][0])
        {
            if(top!=0)
                top = top-1;
        }

        int l = 0;
        int r = matrix[top].size()-1;

        while(l<=r)
        {
            int mid = l+(r-l)/2;

            if(target == matrix[top][mid])
            {
                return true;
            }
            else if(target < matrix[top][mid])
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return false;
    }
};



