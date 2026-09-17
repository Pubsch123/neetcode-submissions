class Solution {
public:
    vector<int> countBits(int n) {
        int x = 1;
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            x = 1;
            int cnt = 0;
            for(int j=0;j<32;j++)
            {
                int k = x<<j;
                if(k > i) break;
                if((k&i)) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
