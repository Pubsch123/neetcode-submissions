class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int r, int c, vector<vector<short>>& sea, vector<vector<int>>& heights)
    {
        sea[r][c] = 1;
        for(int i=0;i<4;i++)
        {
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() 
            && !sea[nr][nc] && heights[nr][nc] >= heights[r][c])
            dfs(nr,nc,sea,heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<short>> pac(row, vector<short> (col,0));
        vector<vector<short>> alt(row, vector<short> (col,0));
        for(int c=0;c<col;c++){
            dfs(0,c,pac,heights);
            dfs(row-1,c,alt,heights);
        }
        for(int r=0;r<row;r++){
            dfs(r,0,pac,heights);
            dfs(r,col-1,alt,heights);
        }
        vector<vector<int>> ans;
        for(int r=0;r<row;r++)
            for(int c=0;c<col;c++)
                if(pac[r][c] && alt[r][c])
                    ans.push_back({r,c});
        return ans;
    }
};
