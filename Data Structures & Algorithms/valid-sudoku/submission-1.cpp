class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            unordered_set<char> ptr;
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.') continue;
                if(ptr.count(board[i][j]))
                return false;
                ptr.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++)
        {
            unordered_set<char> ptr;
            for(int j=0;j<9;j++)
            {
                if(board[j][i] == '.') continue;
                if(ptr.count(board[j][i]))
                return false;
                ptr.insert(board[j][i]);
            }
        }
        for(int i=0;i<9;i++)
        {
            unordered_set<char> ptr;
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    int r = (i/3)*3+j, c = (i%3)*3+k;
                    if(board[r][c] == '.') continue;
                    if(ptr.count(board[r][c])) return false;
                    ptr.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
