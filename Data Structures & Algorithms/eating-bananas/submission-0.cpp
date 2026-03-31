class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid, k ;

        while( l<=r )
        {
            mid = l+ (r-l)/2;
            int temp = 0;

            for(auto pile : piles)
            {
                temp += (pile+mid-1)/mid;
            }
            cout << "mid: " << mid << "temp:" << temp << endl;

            if (temp <= h)
            {
                k = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;;
            }
        }

        return k;
    }
};
