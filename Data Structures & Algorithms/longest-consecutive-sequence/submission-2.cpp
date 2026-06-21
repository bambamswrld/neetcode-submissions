class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {   
            if(!numSet.contains(nums[i] - 1)) 
            {
                int length = 1;
                
                while(numSet.contains(nums[i] + length))
                {
                    length++;
                }
                longest = max(longest, length);
            }
            
        }
        return longest;
    }
};
