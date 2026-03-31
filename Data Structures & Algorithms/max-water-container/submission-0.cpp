class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1; 
        int mA = INT_MIN;

        while (l < r)
        {
            mA = max( mA, (min(heights[l],heights[r]) * (r-l)) );

            cout << "mA:" <<mA << "l:" << l <<"r:"<<r << endl;

            if ( min(heights[l],heights[r]) == heights[l] )
            {
                l++;
            } 
            else
            {
                r--;
            }
        }

        return mA;
    }
};

