class Solution {
public:
    vector<int> countBits(int n) {
        int x = 1;
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            x = i;
            int cnt = 0;
            while(x != 0)
            {
                cnt++;
                x = x&(x-1);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
