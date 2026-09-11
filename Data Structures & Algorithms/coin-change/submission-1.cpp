class Solution {
public:
    unordered_map<int, int> dp;
    int solve(vector<int>& coins, int amt)
    {
        if(amt == 0) return 0;
        if(dp.find(amt) != dp.end()) return dp[amt];
        int res = 1e9;
        for(int coin: coins){
            if(amt - coin >= 0){
                res = min(res, 1+solve(coins, amt-coin));
            }
        }
        return dp[amt] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = solve(coins, amount);
        return (res>=1e9)? -1 : res;
    }
};
