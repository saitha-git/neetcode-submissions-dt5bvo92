class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end   = numbers.size() - 1;
        int sum;

        while (start < end)
        {
            sum = numbers[start]+numbers[end];
            if (target == sum)
            {
                return {start+1,end+1};
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



