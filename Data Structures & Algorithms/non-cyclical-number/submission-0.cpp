class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n!=1)
        {
            int sum = 0;
            while(n>0)
            {
                int k = n%10;
                n = n/10;
                sum += (k*k);
            }
            if(s.find(sum) != s.end()) return false;
            s.insert(sum);
            n = sum;
        }
        return true;
    }
};
