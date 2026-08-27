#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);
        std::queue<int> q;
        std::vector<int> res;
        
        for (auto& p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
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
                    q.push(next);
            }
        }

        if (processed != numCourses)
            return {};
        
        return res;
    }
};
