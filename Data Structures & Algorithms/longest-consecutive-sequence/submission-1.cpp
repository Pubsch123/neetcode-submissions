class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto i: nums)
        s.insert(i);
        int longest = 0;
        for(auto i: s)
        {
            if(s.find(i-1) == s.end())
            {
                int len = 1;
                while(s.find(i+len) != s.end())
                {
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;
    }
};
