class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto l = 0;
        auto n = nums.size();
        for (int r = 0; r < n; r++)
        {
            if (nums[r] != 0)
            {
                swap(nums[r], nums[l]);
                l++;
            }
        }
    }
};