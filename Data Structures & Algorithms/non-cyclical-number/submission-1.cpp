class Solution {
public:
    int squaredSum(int n) {
        int sum = 0;

        while(n) {
            int rem = n%10;
            sum += rem*rem;
            n = n/10;
        }
        cout << sum << endl;
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> seen;
        int sum = squaredSum(n);
        if (sum == 1) {
            return true;
        }
        seen.insert(sum);   
        while (sum != 1)
        {
            sum = squaredSum(sum);        
            if(seen.find(sum) != seen.end()) {
                return false;
            }
            seen.insert(sum);   
        }
        return true;
    }
};
