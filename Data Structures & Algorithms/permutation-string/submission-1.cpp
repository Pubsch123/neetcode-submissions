class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> count1(26,0),count2(26,0);
        for(int i=0;i<s1.size();i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        int l = 0;
        int matches = 0;
        for(int i=0;i<26;i++) 
        if(count1[i] == count2[i]) matches++;
        for(int i=s1.size();i<s2.size();i++,l++)
        {
            if(matches == 26) return true;
            int ind = s2[i]-'a';
            count2[ind]++;
            if(count1[ind] == count2[ind]) matches++;
            else if(count1[ind]+1 == count2[ind]) matches--;
            int idx = s2[l]-'a';
            count2[idx]--;
            if(count1[idx] == count2[idx]) matches++;
            else if(count1[idx]-1 == count2[idx]) matches--;
        }
        return matches == 26;
    }
};
