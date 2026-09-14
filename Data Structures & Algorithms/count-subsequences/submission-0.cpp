class Solution {
public:
    int solve(int i, int j, string& s, string& t, int& n, int& m, vector<vector<int>>& dp)
    {
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int c1 = 0, c2 = 0;
        if(t[j] == s[i])
            c1 = solve(i+1,j+1,s,t,n,m,dp);
        c2 = solve(i+1,j,s,t,n,m,dp);
        return dp[i][j] = c1+c2;
    }
    int numDistinct(string s, string t) {
        if(t.size() > s.size()) return 0;
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return solve(0,0,s,t,n,m,dp);
    }
};
