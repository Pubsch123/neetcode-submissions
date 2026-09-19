class Solution {
public:
    int getSum(int a, int b) {
        int sum, carry;
        while(b!=0)
        {
            sum = a^b;
            carry = a&b;
            carry <<= 1;
            a = sum;
            b = carry;
        }
        return sum;
    }
};
