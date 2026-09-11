class Solution {
public:
    int solve(int i, string& s, vector<string>& wordDict,vector<int>& dp)
    {
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        for(auto j: wordDict){
            if(i+j.size() <= s.size() && s.substr(i,j.size()) == j)
            {
                if(solve(i+j.size(),s,wordDict,dp))
                return dp[i] = 1;
            }
        } 
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return solve(0,s,wordDict,dp);
    }
};
