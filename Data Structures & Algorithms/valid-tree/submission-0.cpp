class Solution {
public:
    bool dfs(int i, int parent, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[i] = 1;
        for(auto node: adj[i])
        {
            if(node == parent) continue;
            if(vis[node] == 1) return false;
            if(!dfs(node,i,adj,vis)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        int cnt = 0;
        for(auto &e: edges)
        {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        dfs(0,-1,adj,vis);
        for(int i=0;i<n;i++)
            if(vis[i] == 0) return false;
        return true;
    }
};
