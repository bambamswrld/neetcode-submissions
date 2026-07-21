class Solution {
private:
    void dfs(vector<int>& candidates, vector<int>& subset, vector<vector<int>>& res, int i, int target)
    {
        if(target == 0)
        {
            res.push_back(subset);
            return;
        }

        if(target < 0)
            return;

        for(int j = i; j < candidates.size(); j++)
        {
            if(j > i && candidates[j] == candidates[j - 1])
                continue;
            subset.push_back(candidates[j]);
            dfs(candidates, subset, res, j + 1, target - candidates[j]);
            subset.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<int> subset;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, subset, res, 0, target);
        return res;
    }
};
