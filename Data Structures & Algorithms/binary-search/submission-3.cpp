class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        auto location = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            auto mid = begin + (end - begin) / 2;
            if(nums[mid] < target)
            {
                begin = begin + 1;
            }
            else if(nums[mid] > target)
            {
                end = end - 1;
            }
            else
            {
                location = mid;
                return location;
            }
        }    
        return location;    
    }
};
