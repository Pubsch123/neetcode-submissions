class Solution {
public:
    int solve(int i, int n, vector<int>& dp)
    {
        if(i >= n){
            if(i == n) return 1;
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int c1 = solve(i+1,n,dp);
        int c2 = solve(i+2,n,dp);
        return dp[i] = c1+c2;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        solve(0,n,dp);
        return dp[0];
    }
};
