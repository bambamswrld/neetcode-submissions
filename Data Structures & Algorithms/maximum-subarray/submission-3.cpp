class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto maxSub = nums[0];
        auto currSum = 0;

        for(const int& n : nums)
        {
            if(currSum < 0)
            {
                currSum = 0;
            }
            currSum += n;
            maxSub = max(maxSub, currSum);
        }
        return maxSub;
    }
};