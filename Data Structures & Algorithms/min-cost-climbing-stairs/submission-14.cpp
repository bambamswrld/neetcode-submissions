class Solution {
// cost: {10, 15, 20, 0}
//
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for (auto i = n - 3; i >= 0; i--)
        {
            cost[i] += std::min(cost[i + 1], cost[i + 2]);
        }

        return std::min(cost[0], cost[1]);
    }
};
