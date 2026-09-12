class Solution {
public:
    int solve(int i, int total, int& n, vector<int>& nums, int& tar, int& sum, vector<vector<int>>& dp)
    {
        if(i == n) return total == tar;
        if(dp[i][total+sum] != -1) return dp[i][total+sum];
        int c1 = solve(i+1,total-nums[i],n,nums,tar,sum,dp);
        int c2 = solve(i+1,total+nums[i],n,nums,tar,sum,dp);
        return dp[i][total+sum] = c1+c2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto &i: nums) sum += i;
        if(target > sum || target < -sum) return 0;
        vector<vector<int>> dp(n, vector<int> (2*sum+1,-1));
        return solve(0,0,n,nums,target,sum,dp);
    }
};
