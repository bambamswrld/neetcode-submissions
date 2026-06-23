class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(auto& num : numSet)
        {
            if(!numSet.contains(num - 1))
            {
                int length = 1;
                while(numSet.contains(num + length))
                {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
