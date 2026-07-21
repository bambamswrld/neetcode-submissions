class Solution {
private:
    std::vector<std::vector<int>> res;
    
    void dfs(vector<int>& nums, vector<int>& subset, int i)
    {
        res.push_back(subset);
        for(int j = i; j < nums.size(); j++)
        {
            if(j > i && nums[j] == nums[j - 1])
            continue;

            subset.push_back(nums[j]);
            dfs(nums, subset, j + 1);
            subset.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        std::vector<int> subset;
        std::sort(nums.begin(), nums.end());
        dfs(nums, subset, 0);
        return res;
    }
};
