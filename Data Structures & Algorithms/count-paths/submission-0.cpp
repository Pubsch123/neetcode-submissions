class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        if(i == m && j == n) return 1;
        int c1 = 0, c2 = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m)
            c1 = solve(i,j+1,m,n,dp);
        else if(j == n)
            c2 = solve(i+1,j,m,n,dp);
        else{
            c1 = solve(i,j+1,m,n,dp);
            c2 = solve(i+1,j,m,n,dp);
        }
        return dp[i][j] = c1 + c2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solve(0,0,m-1,n-1,dp);
    }
};
