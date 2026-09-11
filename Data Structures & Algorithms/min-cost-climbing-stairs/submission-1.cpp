class Solution {
public:
    int solve(int i, int& n, vector<int>& dp, vector<int>& cost)
    {
        if(i >= n) return 0;
        if(dp[i]!=-1) return dp[i];
        int c1 = cost[i]+solve(i+1,n,dp,cost);
        int c2 = cost[i]+solve(i+2,n,dp,cost);
        return dp[i] = min(c1,c2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = min(solve(1,n,dp,cost),solve(0,n,dp,cost));
        return dp[0];
    }
};
