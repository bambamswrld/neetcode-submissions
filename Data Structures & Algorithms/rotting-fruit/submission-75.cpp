class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
    std::queue<std::pair<int,int>> q;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int fresh = 0;
        int time = 0;

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

                int row = curr.first;
                int col = curr.second;
                
                for (int d = 0; d < 4; d++)
                {
                    int nr = row + dirs[d][0];
                    int nc = col + dirs[d][1];

                    if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
