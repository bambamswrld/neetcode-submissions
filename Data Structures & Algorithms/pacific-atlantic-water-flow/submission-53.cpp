class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        
        std::vector<std::vector<bool>> pacific(ROWS, std::vector<bool>(COLS, false));
        
        std::vector<std::vector<bool>> atlantic(ROWS, std::vector<bool>(COLS, false));
        std::vector<std::vector<int>> res;

        for (int r = 0; r < ROWS; r++)
            dfs(heights, r, 0, pacific);
        for (int c = 0; c < COLS; c++)
            dfs(heights, 0, c, pacific);


        for (int r = 0; r < ROWS; r++)
            dfs(heights, r, COLS - 1, atlantic);
        for (int c = 0; c < COLS; c++)
            dfs(heights, ROWS - 1, c, atlantic);

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (pacific[r][c] && atlantic[r][c])
                    res.push_back({r,c});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited)
    {
        visited[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int row = r + dirs[i][0];
            int col = c + dirs[i][1];

            if (row < 0 || col < 0 || row >= ROWS || col >= COLS)
                continue;

            if (visited[row][col])
                continue;
            
            if (heights[row][col] < heights[r][c])
                continue;

            dfs(heights, row, col, visited);
        }
    }
};
