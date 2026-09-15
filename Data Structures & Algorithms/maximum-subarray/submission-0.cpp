class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int cursum = 0, maxsum = nums[0];
       for(auto i: nums)
       {
            if(cursum<0)
                cursum = 0;
            cursum += i;
            maxsum = max(maxsum,cursum);
       } 
       return maxsum;
    }
};
