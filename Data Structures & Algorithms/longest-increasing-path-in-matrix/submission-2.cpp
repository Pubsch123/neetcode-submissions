class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    int dfs(int i, int j,vector<vector<int>>& matrix, vector<vector<int>>& dp, int& n, int& m){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1;
        for(int k=0;k<4;k++)
        {
            int r = i+dir[k][0];
            int c = j+dir[k][1];
            if(r>=0 && r<n && c>=0 && c<m && matrix[r][c] > matrix[i][j]){
                ans = max(ans,1+dfs(r,c,matrix,dp,n,m));
            }
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (m,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans = max(ans,dfs(i,j,matrix,dp,n,m));
        return ans;
    }
};
