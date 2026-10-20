class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int fresh = 0;
        int time = 0;
        std::queue<std::pair<int,int>> q;
        
        
        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)    
                    fresh++;
                if (grid[r][c] == 2)
                    q.push({r, c});
            }
        }
        
        while (fresh > 0 && !q.empty())
        {
            int size = q.size();

            for (auto i = 0; i < size; i++)
            {
                auto [row, col] = q.front();
                q.pop();

                for (auto i = 0; i < 4; i++)
                {
                    int nr = row + dirs[i][0];
                    int nc = col + dirs[i][1];

                    if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1; 
    }
};
