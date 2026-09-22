class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;
        int n = stones.size();
        for(int i=0;i<n;i++)
            pq.push(stones[i]);
        while(pq.size()>1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int res = first-second;
            if(res>0) pq.push(res);
        }
        return pq.size()==1? pq.top():0;
    }
};
