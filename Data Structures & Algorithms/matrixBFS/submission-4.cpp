class Solution {
    int ROWS, COLS;
public:
    int shortestPath(vector<vector<int>>& grid) {
        const auto ROWS = grid.size(), COLS = grid[0].size();
        
        if(grid[0][0] == 1 || grid[ROWS - 1][COLS - 1] == 1)
            return -1;

        std::queue<std::pair<int,int>> q;
        q.push({0,0});
        
        int steps = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [r,c] = q.front();
                q.pop();

                if (r == ROWS - 1 && c == COLS - 1)
                {
                    return steps;
                }

                for (auto d = 0; d < 4; d++)
                {
                    int nr = r + dr[d], nc = c + dc[d];

                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 0) 
                    {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    
};
