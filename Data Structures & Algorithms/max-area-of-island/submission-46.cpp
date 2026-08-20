class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int area = 0;

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    area = std::max(area, bfs(grid, r,c));
                }
            }
        }

        return area;
    }

    int bfs(vector<vector<int>>& grid, int r, int c)
    {
        int step = 1;
        std::queue<std::pair<int,int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        while (!q.empty())
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
                    step += bfs(grid, nr, nc);
                }
            }
        }
        return step;
    }
};
