class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        auto N = grid.size();
        std::vector<std::pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
        std::queue<std::tuple<int,int,int>> q;
        
        if (grid[0][0] == 1 || grid[N - 1][N - 1] == 1)
            return -1;

        q.push({0, 0, 1});
        visited[0][0] = true;

        while (!q.empty())
        {
            auto [r, c, length] = q.front();
            q.pop();

            if (r == N - 1 && c == N - 1)
                return length;
            
            for (auto [dr, dc] : dirs)
            {
                auto nr = r + dr, nc = c + dc;

                if (nr >= 0 && nc >= 0 && nr < N && nc < N && grid[nr][nc] == 0 && !visited[nr][nc])
                {
                    q.push({nr, nc, length + 1});
                    visited[nr][nc] = true;
                }    
            }
        }

        return -1;
    }
};