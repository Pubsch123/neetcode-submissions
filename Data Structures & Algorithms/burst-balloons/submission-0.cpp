class Solution {
public:// Good DP problem must understand everytime.. 
    int solve(int l, int r, vector<int>& nums, int& n, vector<vector<int>>& dp)
    {
        if(l>r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int i=l;i<=r;i++)
        {
            int prod = nums[l-1]*nums[i]*nums[r+1];
            int c1 = solve(l,i-1,nums,n,dp);
            int c2 = solve(i+1,r,nums,n,dp);
            ans = max(ans,c1+c2+prod);
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(1,n-2,nums,n,dp);
    }
};
