class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r = *max_element(piles.begin(),piles.end());
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            int rate = 0;
            for(auto i: piles)
                rate += ceil(double(i)/mid);
            if(rate <= h){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
