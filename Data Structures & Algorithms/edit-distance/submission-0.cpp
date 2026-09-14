class Solution {
public:
    int solve(int i, int j, int& n, int& m, string& word1, string& word2, vector<vector<int>>& dp)
    {
        if(j == m)
        return n-i;
        if(i == n)
        return m-j;
        if(dp[i][j] != -1) return dp[i][j];
        int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
        int ans = INT_MAX;
        if(word1[i] != word2[j])
        {
            c1 = 1 + solve(i+1,j+1,n,m,word1,word2,dp);
            c2 = 1 + solve(i+1,j,n,m,word1,word2,dp);
            c3 = 1 + solve(i,j+1,n,m,word1,word2,dp);
            ans = min(ans,min(c1,min(c2,c3)));
        }
        else
            ans = min(ans,solve(i+1,j+1,n,m,word1,word2,dp));
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0,0,n,m,word1,word2,dp);
    }
};
