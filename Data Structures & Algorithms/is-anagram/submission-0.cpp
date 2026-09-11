class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        map<char,int> mp1,mp2;
        for(int i=0; i<n; i++)
        {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(int i=0; i<n; i++)
            if(mp1[s[i]]!= mp2[s[i]]) return false;
        return true;
    }
};
