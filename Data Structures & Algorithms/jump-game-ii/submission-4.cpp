class Solution {
public:
    // unique way to solve BFS approach without using queue and visited with TC O(n) and Space O(1) space..
    
    //Previous BFS solution has TC - O(N*N) and Space - O(N)
    int jump(vector<int>& nums) { 
        int l = 0, r = 0, res = 0;
        int n = nums.size();
        while(r<n-1){
            int far = 0;
            for(int i = l; i <= r; i++)
            {
                far = max(far,i+nums[i]);
            }
            l = r+1;
            r = far;
            res++;
        }
        return res;
    }
};
