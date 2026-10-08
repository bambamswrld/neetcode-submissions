class Solution {

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ROWS = image.size(), COLS = image[0].size();
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int og = image[sr][sc];
        if (og == color)
            return image;

        std::queue<std::pair<int,int>> q;
        
        q.push({sr, sc});
        image[sr][sc] = color;
        
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dirs[i][0], nc = c + dirs[i][1];
                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && (image[nr][nc] == og))
                {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};