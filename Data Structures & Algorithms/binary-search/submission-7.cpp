class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        auto mid = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            mid = begin + (end - begin) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                begin = begin + 1;
            }
            else
            {
                end = end - 1;
            }
        }    
        return -1;    
    }
};
