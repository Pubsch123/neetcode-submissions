class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.size();
        int res = 0;
        int maxf = 0;
        unordered_map<char, int> mp;
        for(int r = 0;r<n;r++)
        {
           mp[s[r]]++;
           maxf = max(maxf,mp[s[r]]);
           while((r-l+1)-maxf > k){
            mp[s[l]]--;
            l++;
           }
           res = max(res,r-l+1);
        }
        return res;
    }
};
