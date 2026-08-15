class Solution {
int ROWS, COLS;
public:
    int countPaths(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int paths = 0;
        return dfs(grid, 0, 0);
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 1)
            return 0;

        if(r == ROWS - 1 && c == COLS - 1)
            return 1;

        grid[r][c] = 1;
        
        int count = 0;
        count += dfs(grid, r - 1, c);
        count += dfs(grid, r + 1, c);
        count += dfs(grid, r, c - 1);
        count += dfs(grid, r, c + 1);   

        grid[r][c] = 0;
        return count;
    }
};
