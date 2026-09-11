class Solution {
public:
    int t[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool isvalid(int x, int y, int n, int m, vector<vector<char>>& grid)
    {
        return (x>=0 && y>=0 && x<n && y<m && grid[x][y] == '1');
    }
    void dfs(int r, int c, int n, int m, vector<vector<char>>& grid)
    {
        grid[r][c] = '0';
        for(int i=0;i<4;i++)
        {
            if(isvalid(r+t[i][0],c+t[i][1],n,m,grid))
            dfs(r+t[i][0],c+t[i][1],n,m,grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i,j,n,m,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
