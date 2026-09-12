class Solution {
public:
    int solve(int i, int& n, vector<int>& nums, int tar, vector<vector<int>>& dp)
    {
        if(tar<0) return 0;
        if(i == n) return tar == 1000;
        if(dp[i][tar] != INT_MIN) return dp[i][tar];
        int c1 = solve(i+1,n,nums,tar-nums[i],dp);
        int c2 = solve(i+1,n,nums,tar+nums[i],dp);
        return dp[i][tar] = c1+c2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (20001,INT_MIN));
        return solve(0,n,nums,target+1000,dp);
    }
};
