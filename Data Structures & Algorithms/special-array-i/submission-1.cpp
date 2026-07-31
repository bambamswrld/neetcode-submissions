class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        std::vector<std::pair<int, int>> res;

        for (auto i = 0; i < nums.size() - 1; i++)
        {
            res.push_back({nums[i], nums[i + 1]});
        }

        for (auto& r : res)
        {
            if((r.first % 2 == 0 && r.second % 2 != 0) || (r.first % 2 != 0 && r.second % 2 == 0))
                continue;
            else
                return false;
        }

        return true;
    }
};