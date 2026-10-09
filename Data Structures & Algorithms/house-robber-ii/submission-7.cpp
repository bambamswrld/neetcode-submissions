class Solution {
public:
    int rob(vector<int>& nums) {
        auto n = nums.size();
        if (n == 1)
            return nums[0];
        
        return std::max(helper(std::vector<int>(nums.begin(), nums.end() - 1)), helper(std::vector<int>(nums.begin() + 1, nums.end())));
    }

    int helper(std::vector<int> nums)
    {
        auto size = nums.size();
        if (size == 1)
            return nums[0];

        std::vector<int> dp(size);

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (auto i = 2; i < size; i++)
        {
            dp[i] = std::max(dp[i - 1],  dp[i - 2] + nums[i]);
        }

        return dp[size - 1];
    }
};
