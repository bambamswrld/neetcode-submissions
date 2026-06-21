class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        std::set<int> numSet(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {   
            if(numSet.find(nums[i] - 1) == numSet.end()) 
            {
                int length = 1;
                
                while(numSet.find(nums[i] + length) != numSet.end())
                {
                    length++;
                }
                longest = max(longest, length);
            }
            
        }
        return longest;
    }
};
