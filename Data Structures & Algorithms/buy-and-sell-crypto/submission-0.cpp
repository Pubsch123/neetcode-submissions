class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left[n],right[n];
        left[0] = prices[0];
        right[n-1] = prices[n-1];
        int profit = 0;
        right[n-1] = prices[n-1];
        for(int i = 1;i<n;i++)
            left[i] = min(left[i-1],prices[i]);
        for(int i = n-2;i>=0;i--)
            right[i] = max(right[i+1],prices[i]);
        for(int i=0;i<n;i++)
        profit = max(profit,right[i]-left[i]);
        return profit;
    }
};
