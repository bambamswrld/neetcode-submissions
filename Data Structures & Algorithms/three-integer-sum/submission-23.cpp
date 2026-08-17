class Solution {
// {-4, -1, -1, 0, 1, 2}
//.  ^   ^            ^              
//.  i   l            r
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0)
            return {};

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) 
                continue;

            auto l = i + 1;
            auto r = nums.size() - 1;

            while (l < r)
            {
                auto sum = nums[i] + nums[l] + nums[r];

                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }

                    while (l < r && nums[r] == nums[r + 1])
                    {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
