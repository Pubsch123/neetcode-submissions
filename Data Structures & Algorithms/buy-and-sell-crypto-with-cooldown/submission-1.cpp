class Solution {
public:
    int solve(int i, short flag, vector<int>& prices, int& n, vector<vector<int>>& dp)
    {
        if(i >= n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int c1 = 0,c2 = 0;
        if(!flag)
            c1 = solve(i+1,1,prices,n,dp) - prices[i];
        else
            c1 = solve(i+2,0,prices,n,dp) + prices[i];
        c2 = solve(i+1,flag,prices,n,dp);
        return dp[i][flag] = max(c1,c2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0,0,prices,n,dp);
    }
};
