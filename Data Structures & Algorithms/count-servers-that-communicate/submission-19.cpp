class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        std::vector<int> rCount(ROWS, 0);
        std::vector<int> cCount(COLS, 0);
        int count = 0;

        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    rCount[r]++;
                    cCount[c]++;
                }
            }
        }

        for (auto r = 0; r < ROWS; r++)
        {
            for (auto c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1 && (rCount[r] > 1 || cCount[c] > 1))
                    count++;
            }
        }

        return count;
    }   
};