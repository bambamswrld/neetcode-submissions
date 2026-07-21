class Solution {
private:
    std::vector<std::vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& subset, vector<bool>& used)
    {
        if(subset.size() == nums.size())
        {
            res.push_back(subset);
            return;
        }   

        for(int j = 0; j < nums.size(); j++)
        {
            if(used[j])
                continue;
            
            subset.push_back(nums[j]);
            used[j] = true;
            dfs(nums, subset, used);
            used[j] = false;
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();    
        std::vector<int> subset;
        std::vector<bool> used(nums.size());
        dfs(nums, subset, used);
        return res;
    }
};
