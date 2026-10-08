class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::unordered_map<int,int> map;
        auto res = 0;

        for (auto& num : nums)
        {
            res += map[num];
            map[num]++;
        }

        return res;
    }
};