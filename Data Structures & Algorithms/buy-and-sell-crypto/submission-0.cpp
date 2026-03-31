class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=l+1;
        int maxProfit = 0;

        while(r<prices.size())
        {
            if (prices[r]>prices[l])
            {
                maxProfit = max(maxProfit, prices[r]-prices[l]);
                r++;
            }
            else
            {
                l = r;
                r++;
            }
        }

        return maxProfit;
    }
};


