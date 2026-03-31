class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;
        int size = numbers.size();

        for(int i=0; i<size; i++) {
            if(hash.find(numbers[i]) != hash.end()) {
                return vector<int>{hash[numbers[i]], i+1};
            }
            else {
                hash[target-numbers[i]] = i+1;
            }
        }
        
    }
};
