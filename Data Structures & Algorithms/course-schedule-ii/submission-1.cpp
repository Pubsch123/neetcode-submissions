class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<short>& vis, vector<int>& ans)
    {
        vis[i] = 1; // visiting
        for(auto j: adj[i])
        {
            if(vis[j] == 1) return false;
            else if(vis[j] == 0){
                if(!dfs(j,adj,vis,ans)) return false;
            }
        }
        vis[i] = 2; // visited
        ans.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        int n = prerequisites.size();
        vector<short> vis(numCourses,0);
        for(int i=0;i<n;i++)
        {
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            adj[src].push_back(dest);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i] == 0)
            {
                if(!dfs(i,adj,vis,ans))
                  return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
