class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> count;

        for (auto& n : nums) {
            if (count.find(n) != count.end()) { return true; }
            count.insert(n);
        }

        return false;
    }
};