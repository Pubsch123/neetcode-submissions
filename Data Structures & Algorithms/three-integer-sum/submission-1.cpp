class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(a[i]>0) break;
            if(i>0 && a[i] == a[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                vector<int> p;
                if(a[i] + a[j] + a[k] < 0)
                j++;
                else if(a[i] + a[j] + a[k] > 0)
                k--;
                else
                {
                    p.push_back(a[i]);
                    p.push_back(a[j]);
                    p.push_back(a[k]);
                    ans.push_back(p);
                    j++;k--;
                    while(j<k && a[j] == a[j-1]) j++;
                }
            }
        }
        return ans;
    }
};
