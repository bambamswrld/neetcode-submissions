class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDegree(numCourses, 0);
        std::queue<int> q;

        for (auto p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        auto processed = 0;
        while (!q.empty())
        {
            auto course = q.front();
            q.pop();
            processed++;

            for (auto next : adj[course])
            {
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }

        return processed == numCourses;
    }
};
