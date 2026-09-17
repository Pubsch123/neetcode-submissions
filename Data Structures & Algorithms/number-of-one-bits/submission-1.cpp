class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        int x = 1;
        while(x<=n){
            if((x&n)!=0) cnt++;
            x <<= 1;
        }
        return cnt;
    }
};
