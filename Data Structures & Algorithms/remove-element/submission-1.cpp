class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::erase(nums, val);
        int count = 0;
        for(auto& num : nums)
        {
            count++;
        }
        return count;
    }
};