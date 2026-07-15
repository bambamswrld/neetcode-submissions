class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, std::vector<int>>> maxHeap;
        std::vector<std::vector<int>> res;

        for(int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int dist = (x*x) + (y*y);

            maxHeap.push({dist, points[i]});

            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        for(int i = 0; i < k; i++)
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};
