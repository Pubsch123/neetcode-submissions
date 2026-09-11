class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size() || t.size() == 0) return "";
        pair<int, int> res = {-1,-1};
        int reslen = INT_MAX;
        int l = 0;
        unordered_map<char, int> mp, window;
        for(auto i : t)
        mp[i]++;
        int have=0, read = mp.size();
        for(int r=0;r<s.size();r++)
        {
            int c = s[r];
            window[c]++;
            if(mp.find(c) != mp.end() && window[c] == mp[c]) 
                have++;
            while(have == read)
            {
                if(r-l+1<reslen)
                {
                    reslen = r-l+1;
                    res = {l,r};
                }
                window[s[l]]--;
                if(mp.find(s[l]) != mp.end() && window[s[l]] < mp[s[l]]) 
                    have--;
                l++;
            }
        }
        return reslen != INT_MAX? s.substr(res.first,reslen):"";
    }
};
