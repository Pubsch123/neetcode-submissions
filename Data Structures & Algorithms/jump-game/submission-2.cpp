class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size()-1;
        int l = end-1;
        while(l>=0)
        {
            if(l+nums[l]>=end)
                end = l;
            l--;
        }
        return end == 0;
    }
};
