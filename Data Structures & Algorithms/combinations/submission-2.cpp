class Solution {
private:
    std::vector<std::vector<int>> res;
    void dfs(vector<int>& subset, int i, int n, int k)
    {
        if (subset.size() == k)
        {
            res.push_back(subset);
            return;
        }

        for(int j = i; j <= n; j++)
        {
            subset.push_back(j);
            dfs(subset, j + 1, n, k);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        std::vector<int> subset;
        dfs(subset, 1, n, k);
        return res;
    }
};