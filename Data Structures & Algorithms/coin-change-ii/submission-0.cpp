class Solution {
public:
    vector<vector<int>> memo;
    int noOfDistinctCombos(int amount, vector<int>& coins, int idx) {
        if(amount == 0) {
            return 1;
        }
        if (idx < 0) {
            return 0;
        }
        int coin = coins[idx];
        if (memo[idx][amount] != -1) {
            return memo[idx][amount];
        }
        if(coin <= amount) {
            //take
            return memo[idx][amount] = noOfDistinctCombos(amount-coin, coins , idx) +
                                            noOfDistinctCombos(amount, coins, idx-1); 
        } else {
            return memo[idx][amount] = noOfDistinctCombos(amount, coins, idx-1); 
        }

        return memo[coins.size()+1][amount+1];
    }
    int change(int amount, vector<int>& coins) {
        memo.resize(coins.size()+1, vector<int>(amount+1, -1));
        return noOfDistinctCombos(amount, coins, coins.size()-1);
    }
};
