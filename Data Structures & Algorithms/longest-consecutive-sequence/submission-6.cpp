class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){return 0;}
        
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(int num : nums)
        {
            if(!numSet.contains(num - 1))
            {
                int length = 1;
                while(numSet.contains(num + length))
                {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
