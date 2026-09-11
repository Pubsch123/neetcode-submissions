class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        int n = prerequisites.size();
        vector<int> indegree(numCourses,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        for(int i=0;i<numCourses;i++)
            if(indegree[i] == 0)
                q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i: adj[node])
            {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        return ans.size() != numCourses? vector<int>{}: ans;
    }
};
