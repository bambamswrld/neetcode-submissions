class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            bool isEven = (high - mid) % 2 == 0;

            if (nums[mid + 1] == nums[mid]) {
                if (isEven) {
                    low = mid + 2;
                }
                else {
                    high = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if (isEven) {
                    high = mid - 2;
                } 
                else
                {
                    low = mid + 1;
                }    
            } else
                return nums[mid];
        }
        return nums[low];
    }
};