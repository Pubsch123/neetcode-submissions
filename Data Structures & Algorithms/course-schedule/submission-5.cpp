class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<short> indegree(numCourses,0);
        for(int i=0;i<n;i++){
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(indegree[i] == 0) q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto i: adj[node])
            {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        for(int i=0;i<numCourses;i++)
        if(indegree[i] != 0) return false;
        return true;
    }
};
