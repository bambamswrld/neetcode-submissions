class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);
        std::vector<int> res;
        std::queue<int> q;

        for (auto& p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        if (adj.size() > numCourses)
            return {};

        for (auto i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int processed = 0;

        while (!q.empty())
        {
            auto course = q.front();
            q.pop();
            res.push_back(course);
            processed++;

            for (auto next : adj[course])
            {
                if (--indegree[next] == 0)
                {
                    q.push(next);
                }       
            }
        }

        if (processed == numCourses)
            return res;
        
        return {};
    }
};
