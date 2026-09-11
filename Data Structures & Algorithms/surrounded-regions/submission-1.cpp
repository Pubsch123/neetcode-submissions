class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int r, int c, vector<vector<char>>& board)
    {
        board[r][c] = 'V';
        for(int i=0;i<4;i++)
        {
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            if(nr>=0 && nr<board.size() && 
               nc>=0 && nc<board[0].size() && board[nr][nc] == 'O')
               dfs(nr,nc,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i=0;i<c;i++)
        {
            if(board[0][i] == 'O')
            dfs(0,i,board);
            if(board[r-1][i] == 'O')
            dfs(r-1,i,board);
        }
        for(int i=0;i<r;i++)
        {
            if(board[i][0] == 'O')
            dfs(i,0,board);
            if(board[i][c-1] == 'O')
            dfs(i,c-1,board);
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'V') board[i][j] = 'O';
            }
        }
    }
};
