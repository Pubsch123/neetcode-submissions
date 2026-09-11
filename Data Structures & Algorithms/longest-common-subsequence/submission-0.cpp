class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, int& n, int& m, vector<vector<int>>& dp)
    {
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int c1 = 0, c2 = 0, c3 = 0;
        if(s1[i] == s2[j]) c1 = 1 + solve(i+1,j+1,s1,s2,n,m,dp);
        else{
            c1 = solve(i+1,j,s1,s2,n,m,dp);
            c2 = solve(i,j+1,s1,s2,n,m,dp);
            c3 = solve(i+1,j+1,s1,s2,n,m,dp);
        }
        return dp[i][j] = max(c1,max(c2,c3));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(0,0,text1,text2,n,m,dp);
    }
};
