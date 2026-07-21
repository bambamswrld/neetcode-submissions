class Solution {
private:
    std::vector<std::vector<int>> res;
    void dfs(vector<int>& candidates, vector<int>& subset, int i, int target)
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
            dfs(candidates, subset, j + 1, target - candidates[j]);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<int> subset;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, subset, 0, target);
        return res;
    }
};
