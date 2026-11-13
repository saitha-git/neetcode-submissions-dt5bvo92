class Solution {
public:
    vector<vector<int>> memo;
    int minCoins(vector<int>& coins, int amount, int idx) {
        if(amount == 0){
            return 0;
        }
        if(idx < 0) {
            return 1e9;
        }
        if (memo[amount][idx] != -1) {
            return memo[amount][idx];
        }
        if(coins[idx] <= amount) {
            return memo[amount][idx] = min(minCoins(coins, amount, idx-1), 
                       1+minCoins(coins, amount-coins[idx], idx));
        } else {
            return memo[amount][idx] = minCoins(coins, amount, idx-1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount+1, vector<int>(coins.size(), -1));
        int res = minCoins(coins, amount, coins.size()-1);
        return  (res >= 1e9) ? -1 : res;
    }
};
