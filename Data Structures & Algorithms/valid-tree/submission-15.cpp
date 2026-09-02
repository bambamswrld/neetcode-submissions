class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n)
            return false;

        std::vector<std::vector<int>> adj(n);
        std::unordered_set<int> visited;
        std::queue<std::pair<int, int>> q;

        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        q.push({0, -1});
        visited.insert(0);

        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();

            for (auto nei : adj[node])
            {
                if (nei == parent)
                    continue;
                
                if (visited.count(nei))
                    return false;

                visited.insert(nei);
                q.push({nei, node});
            }
        }

        return visited.size() == n;
    }
};
