class Solution {
public:
    int t[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    bool isvalid(int x, int y, int n, int m, vector<vector<int>>& grid)
    {
        return x>=0 and y>=0 and x<n and y<m and grid[x][y] == 1;
    }
    int dfs(int r, int c, int n, int m, int& cnt, vector<vector<int>>& grid)
    {
        grid[r][c] = 0;
        for(int i=0;i<4;i++)
        {
            int nr = r+t[i][0];
            int nc = c+t[i][1];
            if(isvalid(nr,nc,n,m,grid))
            {
                cnt++;
                dfs(nr,nc,n,m,cnt,grid);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt = 1;
                if(grid[i][j] == 1)
                {
                    dfs(i,j,n,m,cnt,grid);
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
