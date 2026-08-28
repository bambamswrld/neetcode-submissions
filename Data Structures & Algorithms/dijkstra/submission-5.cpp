class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;

        for (int i = 0; i < n; i++)
        {
            adj[i] = vector<pair<int, int>>();
        }

        for (vector<int> edge : edges)
        {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d, w});
        }

        std::unordered_map<int, int> shortest;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, src});
        while (!minHeap.empty())
        {
            std::pair<int, int> p = minHeap.top();
            minHeap.pop();

            int w1 = p.first;
            int n1 = p.second;

            if (shortest.count(n1) > 0)
                continue;

            shortest[n1] = w1;

            for (std::pair<int, int> p : adj[n1])
            {
                int n2 = p.first;
                int w2 = p.second;

                if (shortest.count(n2) == 0)
                {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (shortest.count(i) == 0) shortest[i] = -1;
        }
        
        return shortest;
    }
};
