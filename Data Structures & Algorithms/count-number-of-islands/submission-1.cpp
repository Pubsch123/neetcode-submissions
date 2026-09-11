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

    void bfs(int r, int c, int n, int m, vector<vector<char>>& grid)
    {
        queue<pair<int, int>> q;
        q.push({r,c});
        grid[r][c] = '0';
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int newr = node.first;
            int newc = node.second;
            for(int i=0;i<4;i++)
            {
                int rr = newr+t[i][0];
                int cc = newc+t[i][1];
                if(isvalid(rr,cc,n,m,grid))
                {
                    q.push({rr,cc});
                    grid[rr][cc] = '0';
                }
            }
        }
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
                    bfs(i,j,n,m,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
