class Solution {
public:
    string longestPalindrome(string s) {
        int ind = 0, reslen = 0;
        int n = s.size();
        vector<vector<short>> dp(n, vector<short>(n, 0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]))
                {
                    dp[i][j] = 1;
                    if(reslen < (j-i+1)){
                        ind = i;
                        reslen = j-i+1;
                    }
                }
            }
        }
        return s.substr(ind,reslen);
    }
};
