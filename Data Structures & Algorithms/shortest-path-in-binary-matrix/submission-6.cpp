class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        std::vector<std::pair<int,int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        std::vector<std::vector<bool>> visited(n, vector<bool>(n, false));
        std::queue<std::tuple<int,int,int>> q;

        q.push({0, 0, 1});
        visited[0][0] = true;

        while(!q.empty())
        {
            auto [r, c, length] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1) 
                return length;

            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && !visited[nr][nc])
                {
                    q.push({nr, nc, length + 1});
                    visited[nr][nc] = true;
                }
            }
        }
        return -1;
    }
};