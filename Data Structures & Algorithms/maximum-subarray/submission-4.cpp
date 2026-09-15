class Solution {
public:
    int solve(int i, int& n, int flag, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i == n) return flag? 0:INT_MIN;
        if(dp[i][flag] != -1) return dp[i][flag];
        int c1 = INT_MIN, c2 = INT_MIN;
        if(!flag){
            c1 = nums[i] + solve(i+1,n,!flag,nums,dp);
            c2 = solve(i+1,n,flag,nums,dp);
        }else{
            c2 = nums[i] + solve(i+1,n,flag,nums,dp);
            c1 = 0;
        }
        return dp[i][flag] = max(c2,c1);
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return solve(0,n,0,nums,dp);
    }
};
