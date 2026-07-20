class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int i, int target)
    {
        if(target == 0)
            res.push_back(subset);

        if(target < 0)
            return;

        for(int j = i; j < nums.size(); j++)
        {
            subset.push_back(nums[j]);
            dfs(nums, subset, res, j, target - nums[j]);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;

        dfs(nums, subset, res, 0, target);
        return res;
    }
};
