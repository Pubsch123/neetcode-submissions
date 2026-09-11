class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]] = i;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[target-nums[i]]){
                int k = mp[target-nums[i]];
                if(k != i)
                {
                    ans.push_back(i);
                    ans.push_back(k);
                    return ans;
                }
            }
        }
        return ans;
    }
};
