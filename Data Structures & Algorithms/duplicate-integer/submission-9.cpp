class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> counts;
        for (const auto& c : nums)
            if (counts[c]++ == 1)
                return true;
        return false;
    }
};