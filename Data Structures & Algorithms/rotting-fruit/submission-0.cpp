class Solution {
public:
    int t[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    void bfs(vector<vector<int>>& grid, int& cnt, queue<pair<int,int>>& q, int& fresh)
    {
        while(fresh > 0 && !q.empty())
        {
            int size = q.size();
            cnt++;
            for(int k=0;k<size;k++)
            {
                auto cell = q.front();
                q.pop();
                int i = cell.first;
                int j = cell.second;
                for(int p=0;p<4;p++)
                {
                    int l = i + t[p][0];
                    int r = j + t[p][1];
                    if(l>=0 && r>=0 && l<grid.size() && r<grid[0].size() && grid[l][r] == 1)
                    {
                        q.push({l,r});
                        grid[l][r] = 2;
                        fresh--;
                    }
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        bfs(grid,time,q,fresh);
        return fresh == 0? time:-1;
    }
};
