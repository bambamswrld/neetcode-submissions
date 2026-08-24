class Solution {
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
private:
    int ROWS, COLS;
public:  
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));
        vector<vector<int>> res;

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
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS)
                continue;
            if (visited[nr][nc])
                continue;
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(heights, nr, nc, visited);
        }
    }
};
