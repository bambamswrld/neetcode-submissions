class Solution {
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), INF = INT_MAX;

        std::queue<std::pair<int,int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != INF)
                    continue;

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};
