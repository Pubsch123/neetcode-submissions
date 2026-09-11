class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis)
    {
        vis[i] = true;
        for(auto node: adj[i])
        {
            if(vis[node]) continue;
            else dfs(node,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        int cnt = 0;
        for(auto &e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i] == false){
                cnt++;
                dfs(i,adj,vis);
            } 
        }
        return cnt;
    }
};
