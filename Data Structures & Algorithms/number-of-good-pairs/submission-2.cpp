class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size() - 1;
        int count = 0;

        for (int l = 0; l <= n; l++)
        {
            for (int r = l + 1; r <= n; r++)
            {
                if (nums[l] == nums[r])
                    count++;
            }
        }
        return count;
    }
};