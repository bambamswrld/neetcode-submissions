class Solution {
int rowDirs[4] = {-1, 1, 0, 0};
int colDirs[4] = {0, 0, 1, -1};
private:
    int ROWS, COLS;
    std::queue<std::pair<int,int>> q;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        auto fresh = 0;
        auto time = 0;

        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                    fresh++;
                else if(grid[r][c] == 2)
                    q.push({r,c});
            }
        }

        while(fresh > 0 && !q.empty())
        {
            auto length = q.size();

            for (auto i = 0; i < length; i++)
            {
                auto curr = q.front();
                q.pop();

                auto row = curr.first;
                auto col = curr.second;

                for (auto d = 0; d < 4; d++)
                {
                    auto nr = row + rowDirs[d];
                    auto nc = col + colDirs[d];

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
