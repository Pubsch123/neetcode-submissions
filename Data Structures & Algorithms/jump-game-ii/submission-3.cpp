class Solution {
public:
    int jump(vector<int>& nums) { // Good approach to use BFS here..
        int cnt = 0;
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
            for(int j=1;j<=nums[i] && i+j<n ;j++)
                adj[i].push_back(i+j);
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;
        while(!q.empty())
        {
            int size = q.size();
            cnt++;
            while(size--)
            {
                int curidx = q.front();
                q.pop();
                for(auto i: adj[curidx])
                {
                    if(i == n-1)
                        return cnt;
                    if(vis[i] == 0){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        return 0;
    }
};
