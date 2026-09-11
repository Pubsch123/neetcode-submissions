class Solution {
public:
    bool dfs(int i, vector<short>& vis, vector<vector<int>>& adj)
    {
        vis[i] = 1;//visiting
        for(auto j: adj[i])
        {
            if(vis[j] == 1) return false;
            if(vis[j] == 0) { // not visited
                if(!dfs(j,vis,adj))
                return false;
            }
        }
        vis[i] = 2;//visited
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<short> vis(numCourses,0);
        for(int i=0;i<n;i++){
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            adj[src].push_back(dest);
        }
        for(int i=0;i<numCourses;i++)
           if(vis[i] == 0) 
                if(!dfs(i,vis,adj))
                    return false;
        return true;
    }
};
