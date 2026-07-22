class Solution {
private:
    std::vector<std::vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& subset, int i, int target)
    {
        if(target == 0)
        {
            res.push_back(subset);
            return;
        }

        if(target < 0)
            return;

        for(int j = i; j < nums.size(); j++)
        {
            subset.push_back(nums[j]);
            dfs(nums, subset, j, target - nums[j]);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        std::vector<int> subset;
        dfs(nums, subset, 0, target);
        return res;
    }
};
