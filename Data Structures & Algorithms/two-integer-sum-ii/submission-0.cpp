class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end   = numbers.size() - 1;
        vector<int> ans;
        int sum;

        while (start < end)
        {
            sum = numbers[start]+numbers[end];
            if (target == sum)
            {
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
};


