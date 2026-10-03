class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto count = 0;

        for (auto num : nums)
        {
            if (num < target)
                count++;
        }

        return count;
    }
};