class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> count(26, 0);
        std::priority_queue<int> maxHeap;
        std::queue<std::pair<int, int>> q;

        for (auto& task : tasks) count[task - 'A']++;

        for (auto& c : count)
            if (c > 0) maxHeap.push(c);

        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty())
                time = q.front().second;
            else {
                auto cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) q.push({cnt, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
