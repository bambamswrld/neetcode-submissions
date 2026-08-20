class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        auto fresh = 0;
        auto time = 0;
        std::queue<std::pair<int,int>> q;

        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    fresh++;
                }
                else if (grid[r][c] == 2)
                {
                    q.push({r,c});
                }
            }
        }

        while (fresh > 0 && !q.empty())
        {
            auto length = q.size();

            for (auto i = 0; i < length; i++)
            {
                auto curr = q.front();
                q.pop();
                auto r = curr.first;
                auto c = curr.second;

                for (auto d = 0; d < 4; d++)
                {
                    auto row = r + dirs[d][0];
                    auto col = c + dirs[d][1];

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
