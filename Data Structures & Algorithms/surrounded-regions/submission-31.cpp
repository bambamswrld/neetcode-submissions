class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        if (ROWS == 0 || COLS == 0)
            return;

        for (int r = 0; r < ROWS; r++)
        {
            if (board[r][0] == 'O')
                dfs(board, r, 0);
            if (board[r][COLS - 1] == 'O')
                dfs(board, r, COLS - 1);
        }

        for (int c = 0; c < COLS; c++)
        {
            if (board[0][c] == 'O')
                dfs(board, 0, c);
            if (board[ROWS - 1][c] == 'O')
                dfs(board, ROWS - 1, c);
        }

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c)
    {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS)
            return;

        if (board[r][c] != 'O')
            return;
        
        board[r][c] = '#';

        for (int i = 0; i < 4; i++)
        {
            dfs(board, r + dirs[i][0], c + dirs[i][1]);
        }
    }
};
