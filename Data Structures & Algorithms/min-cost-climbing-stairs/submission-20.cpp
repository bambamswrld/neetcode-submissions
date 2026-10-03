class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();

        for (int i = n - 3; i >= 0; i--)
            cost[i] = std::min(cost[i] + cost[i + 1], cost[i] + cost[i + 2]);

        return std::min(cost[0], cost[1]);
    }
};
