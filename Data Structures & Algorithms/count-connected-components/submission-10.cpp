class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::unordered_set<int> visit;
        std::queue<std::pair<int,int>> q;
        int count = 0;

        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (visit.count(i))
                continue;
            
            q.push({i, -1});
            visit.insert(i);
            count++;

            while (!q.empty())
            {
                auto [node, parent] = q.front();
                q.pop();

                for (auto& next : adj[node])
                {
                    if (next == parent || visit.count(next))
                        continue;

                    visit.insert(next);
                    q.push({next, node});
                }
            }
        }

        return count;
    }
};
