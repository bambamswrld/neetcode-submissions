class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        std::vector<std::vector<int>> adj(n + 1);
        std::vector<int> indegree(n + 1, 0);

        std::queue<int> q;
        //std::unordered_set<int> visit;
        
        std::vector<int> res;

        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        for (auto i = 1; i <= n; i++)
        {   
            if (indegree[i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            indegree[node]--;

            for (auto next : adj[node])
            {
                if (--indegree[next] == 1)
                    q.push(next);
            }
        }

        for (auto i = n - 1; i >= 0; i--)
        {
            int u = edges[i][0], v = edges[i][1];
            if (indegree[u] == 2 && indegree[v])
                return {u, v};
        }

        return {};
    }
};
