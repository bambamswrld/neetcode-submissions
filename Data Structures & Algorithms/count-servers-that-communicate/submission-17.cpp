class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int count = 0;
        std::vector<int> rCount(ROWS, 0);
        std::vector<int> cCount(COLS, 0);

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    rCount[r]++;
                    cCount[c]++;
                }
            }
        }

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1 && (rCount[r] > 1 || cCount[c] > 1))
                    count++;
            }
        }
        return count;
    }
};