class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        auto area = 0;

        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    area = std::max(area, dfs(grid, r, c));
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0)
        {
            return 0;
        }

        auto steps = 1;
        
        grid[r][c] = 0;

        for (auto i = 0; i < 4; i++)
        {
            steps += dfs(grid, r + dirs[i][0], c + dirs[i][1]);
        }

        return steps;
    }

};
