class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxL;
        vector<int> maxR;
        int maxLSoFar;
        int maxRSoFar;
        int res = 0;

        if (height.size() == 1)
            return res;

        maxL.push_back(-1);
        maxLSoFar = height[0];

        for(int i=1 ; i<height.size(); ++i)
        {
            maxL.push_back(maxLSoFar);
            maxLSoFar = max(height[i],maxLSoFar);
        }

        for(auto const& elem: maxL)
        {
            cout<<elem<<" ";
        }
        cout << endl;

        maxR.push_back(-1);
        maxRSoFar = height[height.size()-1];

        for(int i= height.size()-2; i>=0; --i)
        {
            maxR.push_back(maxRSoFar);
            maxRSoFar = max(height[i],maxRSoFar);
        }

        reverse(maxR.begin(), maxR.end());

        for(auto const& elem: maxR)
        {
            cout<<elem<<" ";
        }
        cout << endl;

        for(int i=1;i<=height.size()-2;++i)
        {
            if ( min(maxR[i],maxL[i]) > height[i] )
            {
                res += ( min(maxR[i],maxL[i]) - height[i] );
            }
        }

        return res;
    }
};
