class Solution {
public:
    bool solve(int i, int& n, vector<int>& nums, vector<int>& dp)
    {
        if(i >= n-1) return true;
        if(dp[i] != -1) return dp[i];
        for(int j=i+1;j<=min(i+nums[i],n-1);j++)
            if(solve(j,n,nums,dp)) 
                return dp[j] = true;
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) { // DP solution
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};
