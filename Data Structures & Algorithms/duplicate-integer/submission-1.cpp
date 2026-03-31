class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;

        for (auto elem: nums)
        {
            //cout << elem << endl;
            if (hashset.find(elem) != hashset.end())
            {
                return true;
            }
            else
            {
                hashset.insert(elem);
            }
        }

        return false;
    }
};
