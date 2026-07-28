class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        auto count = 0;
        auto sum = 0;

        int l = 0;
        int r = 0;

        while(r < nums.size())
        {

            if(nums[r] == 0)
            {
                l = r + 1;
                r++;
                sum = 0;
            }
            else
            {
                sum++;
                r++;
                count = std::max(sum, count);
            }
            
        }

        return count;
    }
};