class Solution {
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];

        if (orig == color)
            return image;

        dfs(image, sr, sc, orig, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int orig, int color)
    {
        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] != orig)
            return;

        image[r][c] = color;
        
        dfs(image, r + 1, c, orig, color);
        dfs(image, r - 1, c, orig, color);
        dfs(image, r, c + 1, orig, color);
        dfs(image, r, c - 1, orig, color);
    }
};