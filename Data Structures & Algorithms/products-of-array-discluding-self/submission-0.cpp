class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        vector<int> ans;

        for ( auto& num : nums)
        {
            ans.push_back(temp);
            temp = temp*num;
        }

        auto ansV = ans.rbegin();
        temp = 1;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) 
        {
            *ansV = (*ansV)*temp;
            temp = temp * (*it);
            ++ansV;
        }

        return ans;
    }
};
