class Solution {
public:
    int solve(int i, int amt, int& n, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(amt<0 || i == n) return 0;
        if(amt == 0) return 1;
        if(dp[i][amt] != -1) return dp[i][amt];
        int c1=0,c2=0;
        c1 = solve(i,amt-coins[i],n,coins,dp);
        c2 = solve(i+1,amt,n,coins,dp);
        return dp[i][amt] = c1+c2;
    } 
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(0,amount, n, coins,dp);
    }
};
