class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int fresh = 0;
        int time = 0;
        std::queue<std::pair<int, int>> q;

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                    fresh++;
                else if (grid[r][c] == 2)
                    q.push({r, c});
            }
        }

        while (fresh > 0 && !q.empty())
        {
            int length = q.size();

            for (int i = 0; i < length; i++)
            {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (int d = 0; d < 4; d++)
                {
                    int row = r + dirs[d][0];
                    int col = c + dirs[d][1];

                    if (row >= 0 && col >= 0 && row < ROWS && col < COLS && grid[row][col] == 1)
                    {
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row, col});
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
