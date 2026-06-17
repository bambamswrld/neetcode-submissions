class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> numSet;
        for (auto& n : nums) {
            if (numSet.contains(n)) {
                return true;
            } else {
                numSet.insert(n);
            }
        }
        return false;
    }
};