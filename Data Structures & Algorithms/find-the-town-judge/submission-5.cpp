class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<std::vector<int>> adj(n + 1);
        std::vector<int> indegree(n + 1, 0);
        std::vector<int> outdegree(n + 1, 0);
        
        for (auto& t : trust)
        {
            adj[t[0]].push_back(t[1]);
            indegree[t[1]]++;
            outdegree[t[0]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};