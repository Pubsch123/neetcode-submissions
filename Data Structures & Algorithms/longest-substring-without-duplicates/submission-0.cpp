class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int res=0;
        int n = s.size();
        unordered_map<char,int> mp;
        while(r<n)
        {
            if(mp.find(s[r]) != mp.end()) // this check whether key exist or not..

            // if(mp[s[r]])    this check the associated value with that key.. if it will be zero.. it won't enter but technically it should enter inside the if statement for this case.
            
                l = max(mp[s[r]]+1,l);
            mp[s[r]] = r;
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};
