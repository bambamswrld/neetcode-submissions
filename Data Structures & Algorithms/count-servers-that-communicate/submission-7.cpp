class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private: 
    int ROWS, COLS;
public:
    int countServers(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int count = 0;
        std::vector<int> rowCount(ROWS, 0);
        std::vector<int> colCount(COLS, 0);
        
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                    rowCount[r]++;
            }
        }

        for (int c = 0; c < COLS; c++)
        {
            for (int r = 0; r < ROWS; r++)
            {
                if (grid[r][c] == 1)
                    colCount[c]++;
            }
        }

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                    {
                        if (rowCount[r] > 1 || colCount[c] > 1)
                            count++;
                    }
            }
        }
        return count;
    }
};