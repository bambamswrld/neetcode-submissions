class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> ans(nums.begin(), nums.end());
        
        for(auto& num : nums)
        {
            ans.push_back(num);
        }

        return ans;
    }
};