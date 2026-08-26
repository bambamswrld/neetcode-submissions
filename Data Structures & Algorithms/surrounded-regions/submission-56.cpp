class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
    std::queue<std::pair<int,int>> q;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++)
        {
            if (board[r][0] == 'O')
            {
                q.push({r, 0});
                bfs(board, r, 0);
            }
        }

        for (int c = 0; c < COLS; c++)
        {
            if (board[0][c] == 'O')
            {
                q.push({0,c});
                bfs(board, 0, c);
            }
        }

        for (int r = 0; r < ROWS; r++)
        {
            if (board[r][COLS - 1] == 'O')
            {
                q.push({r,COLS - 1});
                bfs(board, r, COLS - 1);
            }
        }
        
        for (int c = 0; c < COLS; c++)
        {
            if (board[ROWS - 1][c] == 'O')
            {
                q.push({ROWS - 1,c});
                bfs(board, ROWS - 1, c);
            }
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

    void bfs(vector<vector<char>>& board, int r, int c)
    {
        board[r][c] = '#';
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            int row = curr.first;
            int col = curr.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && board[nr][nc] == 'O')
                {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
    }
};
