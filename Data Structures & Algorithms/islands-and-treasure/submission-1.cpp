class Solution {
public:
    int t[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int inf = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                pq.push({i,j});
            }
        }
        while(!pq.empty())
        {
            auto ptr = pq.front();
            int r = ptr.first;
            int c = ptr.second;
            pq.pop();
            for(int k=0;k<4;k++)
            {
                int nr = r + t[k][0];
                int nc = c + t[k][1];
                if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc] != inf) continue;
                grid[nr][nc] = min(grid[nr][nc],grid[r][c]+1);
                pq.push({nr,nc});
                
            }
        }
    }
};
