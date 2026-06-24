class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        if(nums.size() == 2)
        {
            if(nums[0] == target)
            {
                return 0;
            }
            else if(nums[1] == target)
            {
                return 1;
            }
            else return -1;
        }

        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target)
            {
                return mid;
            }

            if(nums[l] <= nums[mid])
            {
                if(nums[l] <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if(nums[r] >= target && target >= nums[mid])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
