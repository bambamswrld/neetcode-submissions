class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, std::vector<int>>> maxHeap;
        std::vector<std::vector<int>> res;

        for(auto& point : points)
        {
            auto x = point[0];
            auto y = point[1];

            auto dist = (x*x) + (y*y);

            maxHeap.push({dist, point});
            
            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        for(auto i = 0; i < k; i++)
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};
