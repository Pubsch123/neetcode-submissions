class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t k = 0;
        for(int i=0;i<32;i++)
        {
            k = (1<< i);
            if((k&n) != 0)
            ans = ans + (1 << (31-i));
        }
        return ans;
    }
};
