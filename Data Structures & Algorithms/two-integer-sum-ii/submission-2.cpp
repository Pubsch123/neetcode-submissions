class Solution {
public:
    vector<int> twoSum(vector<int>& a, int tar) {
        int n = a.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(a[i]+a[j] > tar)
            j--;
            else if(a[i] + a[j] < tar)
            i++;
            else return {i+1,j+1};
        }
        return {};
    }
};
