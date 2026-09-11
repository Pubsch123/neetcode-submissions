class Solution {
public:
    int solve(int i, int& n, vector<int>& nums, int sum, vector<vector<int>>& dp)
    {
        if(i == n) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        int c1 = solve(i+1,n,nums,sum-nums[i],dp);
        int c2 = solve(i+1,n,nums,sum,dp);
        return dp[i][sum] = c1|c2;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum&1) return false;
        sum = sum>>1;
        vector<vector<int>> dp(n, vector<int> (sum+1,-1));
        return solve(0,n,nums,sum,dp);
    }
};
