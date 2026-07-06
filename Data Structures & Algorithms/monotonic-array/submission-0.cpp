class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        
        for(int i = 0; i < (int)nums.size() - 1; i++)
        {
            int j = i + 1;
            if(nums[i] > nums[j])
            {
                inc = false;
                break;
            }

        }
        
        for(int i = 0; i < (int)nums.size() - 1; i++)
        {
            int j = i + 1;
            if(nums[i] < nums[j])
            {
                dec = false;
                break;
            }
            j++;
        }

        return inc || dec;
    }
};