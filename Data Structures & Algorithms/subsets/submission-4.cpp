class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int i)
    {
        if(i >= nums.size())
        {
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        dfs(nums, subset, res, i + 1);
        subset.pop_back();
        dfs(nums, subset, res, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        dfs(nums, subset, res, 0);
        return res;
    }
};
