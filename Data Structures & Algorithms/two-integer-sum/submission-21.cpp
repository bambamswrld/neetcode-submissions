class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for(auto i = 0; i < nums.size(); i++)
        {
            auto diff = target - nums[i];
            if(map.contains(diff))
            {
                return {map.at(diff), i};
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};
