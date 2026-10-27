class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> map;

        for(auto num: nums) 
        {
            if(!map.empty() && map.find(num) != map.end()){
                return true;
            }
            map.insert(num);
        }

        return false; 
    }
};