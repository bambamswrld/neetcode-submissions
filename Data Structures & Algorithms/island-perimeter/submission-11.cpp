class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int perimeter = 0;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int nr = r + dirs[d][0];
                        int nc = c + dirs[d][1];
                        if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] == 0)
                            perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};