class Solution {
private: 
    int ROWS, COLS;
public:
    int countServers(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        std::vector<int> rowCount(ROWS, 0);
        std::vector<int> colCount(COLS, 0);
        auto count = 0;

        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }

        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1 && (rowCount[r] > 1 || colCount[c] > 1))
                    count++;
            }
        }
        return count;
    }
};