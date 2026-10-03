class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty())
            return n == 1 ? n : -1;

        std::vector<int> indegree(n + 1, 0);
        std::vector<int> outdegree(n + 1, 0);

        for (auto& t : trust)
        {
            indegree[t[1]]++;
            outdegree[t[0]]++;
        }

        for (auto i = 0; i <= n; i++)
        {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};