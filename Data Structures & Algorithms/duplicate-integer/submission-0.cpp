class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> __set;

        for (auto elem: nums)
        {
            //cout << elem << endl;
            if (__set.find(elem) != __set.end())
            {
                return true;
            }
            else
            {
                __set.insert(elem);
            }
        }

        return false;
    }
};
