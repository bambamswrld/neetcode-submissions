class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, i = 0, n = nums.size();
        
        while(i < n)
        {            
            int j = i;

            while(j < n && nums[j] != 0)
            {
                j++;
            }
               
            maxi = std::max(j - i, maxi);
            i = j + 1;
        }

        return maxi;
    }
};