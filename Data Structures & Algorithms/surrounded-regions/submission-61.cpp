class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++)
            dfs(board, r, 0);
        for (int c = 0; c < COLS; c++)
            dfs(board, 0, c);

        for (int r = 0; r < ROWS; r++)
            dfs(board, r, COLS - 1);
        for (int c = 0; c < COLS; c++)
            dfs(board, ROWS - 1, c);

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] != 'O')
            return;

        grid[r][c] = '#';

        for (int i = 0; i < 4; i++)
        {
            dfs(grid, r + dirs[i][0], c + dirs[i][1]);
        }
    }
};
