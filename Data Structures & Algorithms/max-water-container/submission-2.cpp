class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        cout << r << endl;
        int maxA = INT_MIN;
        int area;
        while(l < r) {
            area = min(heights[l],heights[r]) * (r - l);
            maxA = max(maxA, area);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxA;
    }
};
