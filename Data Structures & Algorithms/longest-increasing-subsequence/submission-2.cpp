class Solution {
public:
    int solve(int prev, int i, int n, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i == n) return 0;
        int c1 = 0, c2 = 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        if(prev == -1) {
            c1 = 1+solve(i,i+1,n,nums,dp);
        }
        else
        {
            if(prev != -1 && nums[i] > nums[prev])
                c1 = 1+solve(i,i+1,n,nums,dp);
        }
        c2 = solve(prev,i+1,n,nums,dp);
        return dp[i][prev+1] = max(c1,c2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(-1,0,n,nums,dp);
    }
};
